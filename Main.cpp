#include <iostream>
#include"Barrier.h"

using namespace std;

int main()
{
	double S0 = 100.0, r = 0.03, sigma = 0.2;
	BSModel Model(S0, r, sigma);

	double T = 1.0 / 12.0, K = 100.0, L=120;
	int m = 30;

	Barrier Option(T, K,L, m);


	long N = 30000;
	double epsilon = 0.001;

	Option.PriceByMC(Model, N, epsilon);
	cout << "Price by direct MC = " << Option.Price << endl;
	cout << "MC Error = " << Option.PricingError << endl;


	return 0;
}


