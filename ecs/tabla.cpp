#include <bits/stdc++.h>
#include <string>
#include "H2-HF.h"

using namespace std;

int main(int args, char *argv[]){
	if (args<4){
		cout << "Faltan argumentos. Escribe el nombre de 3 archivos de entrada '.dat'" << endl;
		return 1;
	}

	H2HF tabla; 
	tabla.exportartabla1(string(argv[1]));
	tabla.exportartabla2(string(argv[2]));
	tabla.exportargrafica(string(argv[3]));
	return 0;
}
