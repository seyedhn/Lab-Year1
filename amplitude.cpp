//Program to calculate the period for a certain pendulum with different amplitudes
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double period(double);
int main()
{
	ofstream file("amplitude.txt");				//file amplitude created

	double theta=0,dtheta=0.1,maxamp=4*atan(1.0);//counters and maximum amplitude declared

	for(int i=0; i<maxamp/dtheta; i++)//for loop to go through 10 times the maxamp value
	{
		theta += dtheta;						//amplitude increases by 0.1 rads
		file << theta << "\t" << period(theta) << endl;//store amplitude and period
	}
	return 0;
}	
	
double period(double amp)
{
	double theta = amp, omega = 0, dt=0.1, tmax = 19, t=0; //floating variables declared
	double const r=9.8, g=9.8;			// constants of gravitation and radius declared
	double pos1=0, pos2=0, counter=0;//first & second time the curve hits theta=0,a counter		
	do
	{
		t += dt;								// increment of time by dt
		theta += omega * dt;					//theta changes by omega*dt
		omega -= g * dt * sin(theta)/r;			//omega changes by g*sin(theta)*dt/r
		
		if(theta <0 && counter==0)	//takes the first position as theta goes negative
		{
			pos1=t;
			counter++;
		}
		if(theta >0 && counter==1)//takes the first position as theta goes back to +ve
		{
			pos2=t;
			counter++;
		}
												
	}
	while (t < tmax);	//perform do while t < tmax						
	return (pos2 - pos1)*2;//return the period = 2 times difference between pos2 & pos1)
	
}
		