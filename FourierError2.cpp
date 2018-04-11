//Program to calculate the average error of a fourier series with respect to different number of terms
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double Four(double, int);	//identify function Four
double AvgError(double);	//identify function AvgError
int main()
{
	
	ofstream file("fouri.txt");	//file fouri created
			
	for(int n=1; n<=1000; n++)	//run through n=1 to n=1000
	{							
		file << n << "\t" << AvgError(n) << endl; //store n and average error
		
	}
	return 0;
}

double Four(double t, int nmax)//function Four to calculate fourier series of a periodic function
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

double AvgError(double n)
{
	double t=0.2, dt=0.01, sum=0.0, term=0.0;	
	for(int i=0; i<280; i++)	//run from t=0.2 to t=3
	{
		
		
		t += dt;					//increment t by 0.1
		term = abs(Four(t,n)-1.0); //error at this interval is the difference between
		//the fourier series and 1
		sum+=term; //add up the errors
	}
	return sum/2.8; //average the total error
}