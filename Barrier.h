#pragma once
#include "BSModel.h"

class PathDepOption
{
public:
	double T, Price, PricingError, delta;
	int m;
	virtual double Payoff(SamplePath& S) = 0;
	double PriceByMC(BSModel Model, long N, double epsilon);
	virtual double PriceByBSFormula(BSModel Model) { return 0.0; }
};

class Barrier :public PathDepOption
{
public:
	double K,L;
	Barrier(double T_, double K_,double L_, int m_) { T = T_;K = K_;L=L_,m = m_; }
	double Payoff(SamplePath& S);
};