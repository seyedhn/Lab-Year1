//Program to calculate the error in a specific fourier series with different terms 
//at different times with respect to the original function
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double Four(double, int);	//identify function Four
int main()
{
	ofstream file("fouri.txt");	//file fouri created
	double t=0.2, dt=0.01, nmax = 1000;	//declare floating variables for counter
	for(int i=0; i<280; i++)	//run through 280 values from t=0.2 to t=3
	{
		t += dt;					//increment t by 0.1
		file << t << "\t" << abs(Four(t,nmax)-1) << endl; //store t and error in file
	}
	return 0;
}

double Four(double t, int nmax)//function Four to calculate fourier series of a period function
{
	double sum=0, term=0, pi=4*atan(1.0), b, w;	//declare varying variables
	const double T = 2*pi, a = 0;				//declare constant given variables
	for(int n=1; n<=nmax; n++)						//run through n times
	{
		b = (n%2)*(4/(n*pi)), w =2*pi*n/T;

		term =a*cos(w*t) + b*sin(w*t);//calculate each term 
		sum += term;							//sum up each term in the sum
	}
	return sum;						//return the sum of terms(final f(t) value)
}