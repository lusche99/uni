// Produkt und Doppelsumme

#include <iostream>
#include <cmath>

using namespace std;

	int main () {
	
	int p = 1, N, i;
	
	cout <<"Bitte Zahl N eingeben!: ";
	cin >> N;
	
	for(i=1; i<=N ; i++) {
	
	cout << " i = " << i-1 << " : Zwischenergebnis = " << p << endl;
	p = p*(3*i-1);
		
  }
	
	cout << "Endergebnis = " << p << endl;
	
	return 0;
	}