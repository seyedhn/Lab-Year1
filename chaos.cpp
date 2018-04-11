//program to calculate the chaos of a double pendulum system
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double motion(double, double);
int main()
{
	ofstream file("Pendulum.txt");// file pendulum created to store values
	
	double dtau = 0.01, taumax = 9, anodmax = 0.25, danod = 0.0002;
	//change in tau, max tau, max anod, change in anod
	//run through from tau = 7 until maxtau by increment of dtau	
	for(double tau=7; tau<=taumax; tau+=dtauikk)
	{
		//run from anod = 0.21 by increment of danod until anodmax
		for(double anod = 0.21; anod<=anodmax; anod+= danod)
		{
			if(motion(anod, tau) < 0)		//if final position of theta is negative
			file << tau << "\t" << anod << endl;// print the corresponding tau and anod
		}	
	}
}
//function to return final position of theta according to the system tau and anod
double motion(double anod, double tau)
{
	double theta = 0, omega = 0, dt=0.1, tmax = 100, a, t=0, pi=4*atan(1.0);
	 //floating variables declared
	double const r=1.0, g=1.0;		// constants of gravitation and radius declared									
	do								//perform the oscillation of pendulum
	{
		t += dt;
		a =	anod*sin(2*pi*t/tau);
		theta += omega * dt;
		omega -= (g*sin(theta) + a*cos(theta))*dt/r;
	}
	while(t < tmax);				//until t = tmax
	return theta;		//returns the final position of theta when t = tmax
}