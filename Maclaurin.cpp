//Calculate the sine function using maclaurin series
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
double maclaurin(double,int);

int main()
{
	ofstream file("maclaurin.txt");	//file maclaurin.txt declared to store results
	double x=0, dx=0.1;	//double type variables declared for x and its increment by 0.1
	for(int i=0; i<=140; i++)	//for loop to go through 141 values from 0 to 140
	{
		file << x << "\t"				//x is stored
			<<maclaurin(x,5)<<"\t"//maclaurin series of up to 5 terms of sin(x) stored
			<<maclaurin(x,10)<<"\t"//maclaurin series of up to 10 terms of sin(x) stored
			<<maclaurin(x,15)<<"\t" << sin(x) << endl;//maclaurin series of up to 10
		//terms of sin(x) stored with the sin(x) function itselft using <cmath> library
		x+= dx;							//x incremented by 0.1
	}
	return 0;
}
double maclaurin(double x, int nterms)// maclarin double typ function initiated
{
	double term=x, sum=x;		//double type variables of term and sum declared with
	//initial values of x. first term is x, so calculation will start from 2nd term
	for(int i=1; i < nterms; i++)//for loop runs from 1 to nterms-1
	{ 
		term = -(term*x*x)/((i*2)*(2*i+1)); //term calculated by product of -, x^2 and 
		//previous term and dividing it by (2i*(2i+1)) which is the factorial term
		sum += term;				//terms are added to sum of maclaurin series terms
	}
	return sum;						//sum is returned
}