//program to calculate the motion of a pendulum
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double period(double);
int main()
{
	ofstream file("Pendulum.txt");	// file pendulum created to store values

	double theta = 0.1, omega = 0, dt=0.1, tmax = 19, t=0; //floating variables declared
		double const r=9.8, g=9.8;				// constants of gravitation and radius declared
	do
	{
		t += dt;								// increment of time by dt
		theta += omega * dt;					//theta changes by omega*dt
		omega -= g * dt * sin(theta)/r;			//omega changes by g*sin(theta)*dt/r
		file << t << "\t" << theta << endl;		//time and position stored in fil
	
	}
	while (t < tmax);							//while t< tmax perform do function
	return 0;
}