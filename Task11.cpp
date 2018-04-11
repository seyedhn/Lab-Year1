//program to give results of a 3rd order polynomial with any given constants
#include <fstream>
using namespace std;

double poly2(double, double, double, double, double);	//function prototype

int main()
{
	ofstream file("poly2.txt");						//file poly2 declared
	double d1=1, c1=-11, b1=18, a1=0;				//the first polynomial constants are declared
	double d2=1, c2=-8, b2=9, a2=18;				//the second polynomial constants are declared
	double dx=0.1, x=0;								// the x and increment in x are initiated
	for(int i =0; i<=100; i++)						//for loop that runs 100 times
	{
		//x & corresponding  values of both polynomials are stored in file							
		file << x << "\t" << poly2(x,a1,b1,c1,d1) << "		" << poly2(x,a2,b2,c2,d2) <<endl;
		x+=dx;										//x incremented by 0.1
	}
	return 0;
}

double poly2(double x, double a, double b, double c, double d)	//function header
{
	double y;										//declaration of dummy variable y
	y = ((d*x + c)*x + b)*x + a;					// evaluation of 3rd power poly done & saved in y
	return y;										//value of y is returned
}

			
