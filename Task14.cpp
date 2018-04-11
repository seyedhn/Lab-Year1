#include <iostream>
#include <vector>									//vector class included
#include <cmath>									//cmath included to perform sqrt function
using namespace std;

int main()
{		
	vector<double> vec(3);								//vector vec with 3 elements declared
	
	cout << "Please enter the vector components" << endl;//ask user to input components
	cin >>  vec[0] >> vec[1] >> vec [2];				//input the components
	
	double mag = sqrt(vec[0]*vec[0] + vec[1]*vec[1] + vec[2]*vec[2]);//calculate magnitude
	
	cout << mag << endl;								//print the magnitude						
	
	return 0;
}
/*Results:
Please enter the vector components
3			7			1
4			9			15
5			12			8
7.07107		16.5529		17.0294
*/
