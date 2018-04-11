//program to calculate the motion of a double pendulum system
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double period(double);
int main()
{
	ofstream file("Pendulum.txt");	// file pendulum created to store values

	double theta = 0, omega = 0, dt=0.1, tmax = 100, a, t=0, pi=4*atan(1.0);
//angular displacement ,angular velocity, change in time, maximum time
	double const r=1.0, g=1.0, anod=0.2, tau = 2*pi;//system constants are declared								
//radius of lower pendulum, gravitational constant, amplitude constant, time constant
	do
	{
		t += dt;										//t incremented by dt
		a =	anod*sin(2*pi*t/tau);//horizontal acceleration of upper mass is calculate 
		theta += omega * dt;		//theta is changed by a change in omega
		omega -= (g*sin(theta) + a*cos(theta))*dt/r;//angular velocity is changed
		file << theta << "\t" << omega << endl;	//print theta with corresponding omega
	}
	while(t < tmax);		//run through until t = tmax
	return 0;
}
