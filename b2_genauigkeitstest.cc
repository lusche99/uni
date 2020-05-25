// Genauigkeitstest

#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	double eps = 1.0, gen; 
	
	do {
		eps = eps / 2;
	}
	while(1 != 1+eps);
	
	gen = eps * 2;
	
		cout<<"Genauigkeit "<< gen << endl;
		
	return 0;
	}