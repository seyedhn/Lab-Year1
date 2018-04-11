//Program to calculate the output voltage of a low pass filter using Fourier series
#include <fstream>
#include <iostream>
#include <cmath>
using namespace std;
double Fourier(double, int, double, double);					//identify function Fourier
int main()
{
	ofstream file("fouri2.txt");							//file fouri2 created
	double t, tnod=0,tmax=6.3, dt=0.01, pi=4*atan(1.0);	//declare floating variables
	double T = 2*pi, Tau = 0;								//assign period T and time constant Tau
	int nmax = 1000;										//maximum number of terms of the fourier series
	for(t=tnod; t<=tmax; t+=dt)								//run through tmax times
	{
		file << t << "\t" << Fourier(t, nmax, Tau, T) << endl;//store t and f(t) in file
	}
	return 0;
}

double Fourier(double t, int nmax,double Tau, double T)		//function Fourier to calculate fourier series of a low pass filter output voltage function
{					
	double sum=0, term=0, pi=4*atan(1.0);					//floating variables declared
										
	for(int n=1; n<=nmax; n+=2)								//run through n times
	{
		double w = 2*pi*n/T;								//omega w defined as 2*pi*n/T
		double A = 1/(n*(sqrt(1+w*w*Tau*Tau)));				//Amplitude of each term is defined
		double fi = -atan(w*Tau);							//the phase of the sine term is defined
		term =A*sin(w*t+fi);								//Fourier series term calculated
		sum += term;										//terms are summed up in sum
	}
	return 4*sum/pi;										//return 4/pi times the total sum which is the value of f(t)
}
