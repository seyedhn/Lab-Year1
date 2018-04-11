#include"FConv.h"
int main()
{
	
	ofstream file("fouri.txt");										//file fouri created
	int n, counter;													//declare number of terms and counter(to exit the loop when condition satisfied)
	double pi=4*atan(1.0), tnod=0.5, tmax=3, dt=0.01, nmax = 10000, minerror=0.00005;		//input  time interval, time steps, maximum number of terms nmax and convergence point
	
	double Tau = 1, Tnod = 0, Tmax=3.1, dT = 0.01, T ;						//input Tau, Taumax,, initial period Tnod, maximum period Tmax and period step dT
	for(T=Tnod; T<=Tmax; T+=dT)										//run through different periods from Tnod to Tmax
	
	//double T = 2*pi, Taunod = 0, Taumax = 0.9, dTau=0.1, Tau;			//input period T, initial, maximum and step increment of Tau
	//for(Tau=Taunod; Tau<Taumax; Tau+=dTau)								//run through different Tau's starting from Taunod to Taumax
	{
	n = 1;																//set number of terms to 1
	counter = 0;														//set counter to be 0
	while(n<=nmax && counter ==0)										//while n is less than nmax and counter is 0
	{							
		
		if(AvgError(n,Tau,tnod,tmax,dt,T) <= minerror)					//If error in function is less than convergence point
		{
			//file << Tau << "\t" << n << endl;								//record the period T and the number of terms with which the function has converged
			file << T << "\t" << n << endl;							////record Tau and the number of terms with which the function has converged
			counter++;													//increase counter by 1 to stop the while loop
		}
		n++;															//increment n by 1
		
	}
		
	}
	return 0;
}


