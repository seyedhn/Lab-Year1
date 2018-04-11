//calculate the factorial of numbers from 1 to 10
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream stream1("factor");		//file factor declared to stream1
	
	int nfact = 1, nmax = 10;		//declare variables
	for(int n = 1; n <= nmax; n++)	//initialise for loop to go through numbers 1 to 10
	{
		nfact *= n;					//calculate nfact by multiplying it by n
		cout << nfact << endl;		//print the value of nfact
		stream1 << nfact << endl;	// nfact stored in stream1
	}
	return 0;
}
