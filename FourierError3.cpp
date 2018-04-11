//Program to calculate the average error of fourier series in a low pass filter with different number of terms
//
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double Fourier(double,int,double,double);								//identify function Four
double AvgError(int,double,double,double,double,double);			//identify function AvgError (the average error in a function f(t))
double Fourierlarge(double, double,double);							//identify function Fourlarge(a simulation of actual fnction)
int main()
{
	
	ofstream file("fouri.txt");										//file fouri created
	
	double pi=4*atan(1.0);	
	double T = 2*pi, Tau = 1, tnod=0.8, tmax=2.4, dt=0.1, nmax=500;	//input time interval, time step, period, Tau and number of terms
	for(int n=1; n<=nmax; n++)										//run through from n=1 to nmax
	{							
		file << n << "\t" << AvgError(n,Tau,tnod,tmax,dt,T) <<endl; //store n and corresponding average error in file
		
	}
	return 0;
}

double Fourier(double t, int nmax,double Tau,double T)					//functgrion Four to calculate fourier series of a low pass filter voltage function
{										
	double sum=0, term=0, pi=4*atan(1.0);							//floating variables declared
								
	for(int n=1; n<=nmax; n++)										//run through nmax times
	{
		double w = 2*pi*n/T;										//omega w defined as 2*pi*n/T for simplicity
		double A = 1/(n*(sqrt(1+w*w*Tau*Tau)));						//the amplitude of each term is defined
		double fi = -atan(w*Tau);									//the phase of the sine function defined
		term =A*sin(w*t+fi);										//Fourier series term calculated
		sum += term;												//terms are summed up in sum
	}
	return 4*sum/pi;												//return 4/pi times the total sum which is the value of f(t)
}

double Fourierlarge(double t,double Tau,double T)						//function to calculate fourier series with 100,000 terms of a low pass filter voltage function
{									
	double sum=0, term=0, pi=4*atan(1.0);							//floating variables declared
							
	for(int n=1; n<=100000; n++)									//run through 100000 times
	{
		double w = 2*pi*n/T;										//omega w defined as 2*pi*n/T for simplicity
		double A = 1/(n*(sqrt(1+w*w*Tau*Tau)));						//the amplitude of each term is defined
		double fi = -atan(w*Tau);									//the phase of the sine function define
		term =A*sin(w*t+fi);										//term calculated
		sum += term;												//terms are summed up in sum
	}
	return 4*sum/pi;												//return 4/pi times the total sum, very close value of the total function
}

double AvgError(int n, double Tau, double tnod, double tmax, double dt,double T)//function that calculates the average error of the fourier series 

{
	double  sum=0, term=0.0;										//declare floating variables
	for(double t=tnod; t<=tmax; t+=dt)								//run through tnod to tmax
	{
		
		term = abs(Fourier(t,n,Tau,T)-Fourierlarge(t,Tau,T));				 //calculate the error at each time instance
//
		sum+=term;													//add the errors up
	}
	return (sum*dt)/(tmax-tnod);									//return the average error
}

