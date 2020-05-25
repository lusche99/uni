#include <iostream>
#include <cmath>

using namespace std;

int main() {
	
	int i, N, j;
	float Summe = 0;

	cout << "Enter N ";
	cin >> N;
	
	// Erste Schleife für Summe über i	
	for ( i = 1 ; i<= N; i++) {
		
		// Zweite Schleife für Summe über j
		for( j = 1; j <= i; j++) {
		Summe = Summe + (1.0/(i*j)); // Warum 1.0 nicht 1 ?
	
		}	
	}

	cout <<"Summe = " << Summe << endl;

  }