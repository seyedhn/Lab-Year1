// program to calculate the third power of a number
#include <iostream>
using namespace std;
int main() 
{
	int n, ncube;
	cout << "Enter a number:" ;
	cin >> n;
	if(n < 0)
	{
		cout << "The number entered is negative" << endl;
		exit(99);
	}
	ncube = n*n*n; // Assign the value of n*n*n to ncube
	cout << n << "\t" << ncube << endl;
	return 0;
}