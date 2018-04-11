#include <fstream>
#include <iostream>
using namespace std;

double poly(double&);	//function poly declared with prototype of type double&

int main()
{
	double z =1.5;		//floating point z initialised to 1.5
	cout << "z before is " << z << "\t";	//print value of z
	cout << "poly = " << poly(z) << endl;	//print poly(z);
	cout << "z after is " << z << "\t";		//print z again after it has altered by poly function
	return 0;
}

double poly(double& x)						//poly initialized with passing by refernece variable x
{
	double y;								//floating piint y declared
	const double a=0, b=18, c=-11, d=1;		//polynomial constants declared
	y=((d*x+c)*x+b)*x+a;					//polynomial y evaluated
	x=0;									// variable x changed to 0
	return y;
}
/*results
z before is 1.5 poly 5.625
z after is 0
*/