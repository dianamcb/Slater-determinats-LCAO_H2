#include "H2-HF.h"

using namespace std;

H2HF::H2HF(void){
	var1=0;
	var2=0;
	var3=0;
}

void H2HF::casos(double r, double &var1, double &var2, double &var3){
	if (r==0.){
		var1=0.625;
		var2=0.625;
		var3=0.625;
	} else if (r==1.){
		var1=0.554521;
		var2=0.507045;
		var3=0.436651;
	} else if (r==1.5){
		var1=0.490338;
		var2=0.405369;
		var3=0.296835;
	} else if (r==2.0){
		var1=0.425974;
		var2=0.308036;
		var3=0.184156;
	} else if (r==2.5){
		var1=0.368388;
		var2=0.225595;
		var3=0.106622;
	} else if (r==3.){
		var1=0.319804;
		var2=0.160742;
		var3=0.058508;
	} else if (r==3.5){
		var1=0.279944;
		var2=0.112156;
		var3=0.030766;
	} else if (r==5.){
		var1=0.199569;
		var2=0.034953;
		var3=0.003717;
	} else if (r==7.){
		var1=0.142845;
		var2=0.006538;
		var3=0.000168;
	} else cout << "Error: no es valor para rab" << endl;
}
double H2HF::T11(double r){return 0.5;}
double H2HF::T12(double r){return -0.5*(S12(r)-2*(1+r)*exp(-r));}
double H2HF::T22(double r){return T11(r);}
double H2HF::V11A(double r){return -1.;}
double H2HF::V22A(double r){return V11B(r);}
double H2HF::V11B(double r){return -(1./r)+(1.+(1./r))*exp(-2.*r);}
double H2HF::V22B(double r){return V11A(r);}
double H2HF::V12A(double r){return -(1.+r)*exp(-r);}
double H2HF::V12B(double r){return V12A(r);}
double H2HF::S12(double r){return (1.+r+((1./3)*(r*r)))*exp(-r);}
double H2HF::F1111(double r) {return 5./8;}
double H2HF::F1122(double r){
	return 1./r*(1.-(1.+11./8.*r+3./4.*r*r+1./6.*r*r*r)*exp(-2.*r));
}
double H2HF::F1112(double r){
	return (r+1./8.+5./(16.*r)-(1./8.+5./(16.*r))*exp(-3.*r))*exp(-r);
}
double H2HF::A(double r){
	return (1.-r+1./3.*r*r)*exp(r);
}
double H2HF::F1212(double r) {
	return 1./5.*((25./8.-23./4.*r-3.*r*r-1./3.*r*r*r)*exp(-2.*r)+(6./r)*((0.57722+log(r))*S12(r)*S12(r)+A(r)*A(r)*expint(-4.*r)-2.*A(r)*S12(r)*expint(-2.*r)));
}

double H2HF::J11(double r){
	return 1./((1.+S12(r))*(1.+S12(r)))*(0.5*F1111(r)+0.5*F1122(r)+F1212(r)+2*F1112(r));
}
double H2HF::J12(double r){
	return 1./(1-S12(r)*S12(r))*(0.5*F1111(r)+0.5*F1122(r)-F1212(r));
}
double H2HF::K12(double r){
	return 1./(2*(1-S12(r)*S12(r)))*(F1111(r)-F1122(r));
}
double H2HF::J22(double r){
	return 1./((1-S12(r))*(1-S12(r)))*(0.5*F1111(r)+0.5*F1122(r)+F1212(r)-2*F1112(r));
}
double H2HF::H11C(double r){return T11(r)+V11A(r)+V11B(r);}
double H2HF::H12C(double r){return T12(r)+V12A(r)+V12A(r);}
double H2HF::E1C(double r){return 1./(2+2*S12(r))*(H11C(r)+H11C(r)+H12C(r)+H12C(r));}
double H2HF::E2C(double r){return 1./(2-2*S12(r))*(H11C(r)-H12C(r)-H12C(r)+H11C(r));}
double H2HF::ET(double r){
	return (T11(r)+T22(r)+V11A(r)+V22B(r))/(1+S12(r))+(V11B(r)+V22A(r))/(1+S12(r))+J11(r)+1./r+2*(V12A(r)+V12B(r)+T12(r))/(1+S12(r));
}
void H2HF::exportartabla1(string name1){
	ofstream table(name1);
	table<<"#rAB\tS12\tT12\tV11B\tV12A\t(11,22)\t(11,12)\t(12,12)"<<endl;
	for(auto i: r){
//		casos(i, var1, var2, var3);
		table<<i<<"\t"<<S12(i)<<"\t"<<T12(i)<<"\t"<<V11B(i)<<"\t"<<
			V12A(i)<<"\t"<<F1122(i)<<"\t"<<F1112(i)<<"\t"<<F1212(i)<<"\n";
	}
	table.close();
}
void H2HF::exportartabla2(string name2){
        ofstream table(name2);
        table<<"#rAB\tE1C\tE2C\tJ11\tJ12\tJ22\tK12\t1/rAB"<<endl;
        for(auto i: r){
                table<<i<<"\t"<<E1C(i)<<"\t"<<E2C(i)<<"\t"<<J11(i)<<"\t"<<
                        J12(i)<<"\t"<<J22(i)<<"\t"<<K12(i)<<"\t"<<1./i<<"\n";
        }
        table.close();
}
void H2HF::exportargrafica(string name3){
        ofstream table(name3);
        table<<"#rAB\tET"<<endl;
        for(float i=0.1;i<10;i+=0.1){
                table<<i<<"\t"<<ET(i)<<"\n";
        }
        table.close();
}
