//program to evaluate sine(x) function
#include <cmath>		//include maths functions
#include <fstream>		//include fstream function to store data in file

using namespace std;

int main()
{
	ofstream file("sinfunction.txt");	//file(sinfunction.txt) declared
	double sine, dx=0.1, x=0;			//floating variables declared
	for(int i=0; i<=140; i++)			//for loop to go over 141 values from 0 - 140
	{		
		sine = sin(x);					//sine(x) is evaluated and stored in sine
		file << x << "\t" << sine << endl; //x	sine values are saved to the file sinfunction
		x+=dx;							// x incremented by 0.1
	}
	return 0;
}
