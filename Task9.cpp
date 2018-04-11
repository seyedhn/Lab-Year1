//calculate the factorial of numbers from 1 to 20 using int and double variables
#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream stream1("factor");			//file factor declared to stream1
	int intfact = 1;					//declare int variable
	double doublefact = 1, nmax = 20;	//declare floating point variables 
	for(int n = 1; n <= nmax; n++)		//initialise for loop to go through numbers 1 to 20
	{
		intfact *=n;					//calculate intfact by multiplying it by n
		doublefact *= n;				//calculate doublefact by multiplying it by n
		cout <<  intfact << "			" << doublefact << endl;	//print the value of nfact
		stream1 << intfact << "			" << doublefact << endl;	// nfact stored in stream1
	}
	return 0;
}

/*output when nfact declared as
int					double
1					1
2					2
6					6
24					24
120					120
720					720
5040				5040
40320				40320
362880				362880
3628800				3.6288e+006
39916800			3.99168e+007
479001600			4.79002e+008
1932053504			6.22702e+009
1278945280			8.71783e+010
2004310016			1.30767e+012
2004189184			2.09228e+013
-288522240			3.55687e+014
-898433024			6.40237e+015
109641728			1.21645e+017
-2102132736			2.4329e+018
*/
