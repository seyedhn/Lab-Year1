#include"FConv.h"
double Fourier(double t, int nmax,double Tau,double T)		//function Fourier to calculate fourier series of a low pass filter voltage function
{										
	double sum=0, term=0, pi=4*atan(1.0);					//floating variables declared
							
	for(int n=1; n<=nmax; n++)								//run through up to nmax
	{
		double w = 2*pi*n/T;								//omega w defined as 2*pi*n/T
		double A = 1/(n*(sqrt(1+w*w*Tau*Tau)));				//Amplitude of each term is defined
		double fi = -atan(w*Tau);							//the phase of the sine term is defined
		term =A*sin(w*t+fi);								//Fourier series term calculated
		sum += term;										//terms are summed up in sum
	}
	return 4*sum/pi;										//return 4/pi times the total sum
}

double Fourierlarge(double t,double Tau,double T)			//function to calculate fourier series with 100,000 terms of a low pass filter voltage function
{									
	double sum=0, term=0, pi=4*atan(1.0);					//floating variables declared
							
	for(int n=1; n<=10000; n++)								//run through 100000 times
	{
		double w = 2*pi*n/T;								//omega w defined as 2*pi*n/T
		double A = 1/(n*(sqrt(1+w*w*Tau*Tau)));				//Amplitude of each term is defined
		double fi = -atan(w*Tau);							//the phase of the sine term is defined
		term =A*sin(w*t+fi);								//Fourier series term calculated
		sum += term;										//terms are summed up in sum
	}
	return 4*sum/pi;										//return 4/pi times the total sum
}

double AvgError(int n, double Tau, double tnod, double tmax, double dt,double T)//function that calculates the average error of the fourier series 

{
	double  sum=0, term=0.0;								//declare floating variables
	for(double t=tnod; t<tmax; t+=dt)						//run through from tnod to tmax
	{
		t += dt;											//increment t by dt
		term = abs(Fourier(t,n,Tau,T)-Fourierlarge(t,Tau,T));//calculate the error at each time instance

		sum+=term;											//add the errors
	}
	return (sum*dt)/(tmax-tnod);							//return the average error
}