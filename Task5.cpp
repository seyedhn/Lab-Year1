//Calculate 3rd power of n for all n in range of 1 to 8
#include <iostream>
using namespace std;
int main()
{
	int n = 1, ncube;					//declare variables
	do 
	{
	ncube = n*n*n;						// calculate 3rd power of n
	cout << n << "	" << ncube << endl;	//calculate 3rd power of n for n<=8
	n++;
	}
	while (n<=8);						//while loop to perform do function
	return 0;
}

