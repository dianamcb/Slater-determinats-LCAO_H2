#ifndef H2HF_H
#define H2HF_H
#include <bits/stdc++.h>

using namespace std;

class H2HF{
	public:
	H2HF(void);
	double T11(double r);
	double T12(double r);
	double T22(double r);
	double V11A(double r);
	double V22A(double r);
	double V11B(double r);
	double V22B(double r);
	double V12A(double r);
	double V12B(double r);
	double S12(double r);
	double F1(double r);
	double J11(double r);	
	double J12(double r);
	double J22(double r);
	void exportartabla1(string name1);
	void exportartabla2(string name2);
	void exportargrafica(string name3);
	void casos(double r, double &var1, double &var2, double &var3);
	double F1111(double r);
	double F1212(double r);
	double F1122(double r);
	double F1112(double r);
	double A(double r);
	double H11C(double r);
	double H12C(double r);
	double E1C(double r);
	double E2C(double r);
	double K12(double r);
	double ET(double r);


	private:
	double var1;
	double var2;
	double var3;
	double r[9]={0., 1., 1.5, 2., 2.5, 3., 3.5, 5., 7.};
};

#endif
