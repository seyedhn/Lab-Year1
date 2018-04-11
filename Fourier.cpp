//Program to calculate a periodic function by expanding and evaluating the Fourier series
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double Four(double, int);	//identify function Four
int main()
{
	
	ofstream file("fouri.txt");	//file fouri created
	int nmax = 100;
	double t, tnod=0, tmax=6.3, dt=0.1;	//declare floating variables for counter
	for(t=tnod; t<=tmax; t+=dt)	//run through 188 values(6*pi = 3 cycles = 18.8)
	{
							//increment t by 0.1
		file << t << "\t" << Four(t,nmax) << endl; //store t and f(t) in file
		t += dt;
	}
	return 0;
}

double Four(double t, int nmax)//function to calculate fourier series of a periodic function
{
	double sum=0, term=0, pi=4*atan(1.0), b, w;	//declare varying variables
	const double T = 2*pi, a = 0;				//declare constant given variables
	for(int n=1; n<=nmax; n+=2)						//run through n times
	{
		b = 4/(n*pi);
		w = 2*pi*n/T;

		term =b*sin(w*t);//calculate each term 
		sum += term;				//sum up each term in the sum
	}
	return sum;						//return the sum of terms(final f(t) value)
}