//Calculate third or fourth power of an integer
#include <iostream>
using namespace std;
int main()
{
	int n, m, power;
	cout << "Enter a number:" << endl;
	cin >> n;
	cout << "Now enter the power:" << endl;
	cin >> m;
	switch(m)
	{
	case 3:
		power = n*n*n;
		break;
	case 4:
		power = n*n*n*n;
		break;
	default:
		cout << "Input error: The power entered is not 3 or 4" << endl;
		exit(99);
	}
	cout << power << endl;
	return 0;
}