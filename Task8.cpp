//C++ Program
#include <fstream>
using namespace std;
int main()
{
	ofstream myfile("polyval.txt");				//output is stored in file "polyval.txt"
	const double dx = 0.10, a = 0.0, b = 18.0, c = -11.0, d = 1.0;//polynomial constants are declared
	double x = 0.0, poly;		//x variable is declared
	for(int i=0; i<100; i++)	//an integer for loop from 0 to 100
	{
		x+=dx;					//increments the x variable by 0.1
		poly = ((d*x + c)*x +b)*x +a;		//the evaluation is performed
		myfile << x << "\t" << poly << endl;	//results are sent to myfile
	}
	return 0;
}