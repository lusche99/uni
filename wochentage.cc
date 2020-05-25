// Berechnung des Wochentages

#include <iostream> 
#include <cmath>

using namespace std;

//Schaltjahrtest: ist j%100 != 0 j ist kein sj,  ist j%400 = 0 ist j sj

int schaltjahr (int j) {
	// default: j ist kein schaltjahr
	int schaltjahr = 0;
	
	// Schaltjahr wenn gilt :
	if (j % 400 == 0 ) {
		schaltjahr = 1;
	}
	if ((j % 100 != 0) && (j % 4 == 0)){
		schaltjahr = 1;
	}	
		return schaltjahr;
}

// Berechne wv Tage im laufenden Jahr vergangen sind

int main() {
	
	// referenz Tag 1.1.1871, ein Sonntag ( also wt mod 7 = 0 entspricht Sonntag)
	
	int jahr0 = 1871, monat0 = 1, tag0 = 1, count = 0;
	int djahre, wochentag;
	int dtage = 0;
	int monatSJ[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int monatKSJ[12] ={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	
	// Einlesen der Information
	
    cout << "Bitte Datum eingeben: (Tag Monat Jahr(ab 1871)): " ;
    int Tag=0, Monat=0, Jahr=0;
    cin >> Tag >> Monat >> Jahr ;


	int m = 0;
	
	// Tage beachten
	
	djahre = Jahr - jahr0;

	// unvollständige Monate im unvollständigen Jahr beachten; ist angebenes Jahr SJ oder nicht ?
	if ( Monat > 1) {
		if(schaltjahr(Jahr) == 0 ) {
			while ( m < Monat ) {
				dtage = 365 - monatKSJ[m]; // Berechne wv Tage im Jahr vergangen sind -> 365 - Tage  
				m++; 
			}dtage = (365 - dtage - Tag - 1); cout <<"Tage die zur Differenz zaehlen :" << dtage << " im Jahr: "<< Jahr  << endl;
		}else if (schaltjahr(Jahr) == 1){
			while ( m >= 0) {
				dtage = dtage + monatSJ[m];
				m--;
			}dtage = 366 - dtage - (Tag - 1); cout <<"Tage die zur Differenz zaehlen :" << dtage << " im Jahr: "<< Jahr  << endl;
		}
	}else dtage = dtage + 31 - Tag;
	
	//Volle Jahre berechnen
	
	for ( int i = jahr0; i < Jahr; i++) {
		if (schaltjahr(i) == 0 ) { // i ist kein schaltjahr
			dtage = dtage + 365;
			}else if (schaltjahr(i) == 1) { // i ist schaltjahr, für jedes sj im intervall einen tag addieren
			dtage = dtage + 366; count++;
		}
	}	
	
	cout <<"Schaltjahre im Intervall: "<< count << endl;
	
	cout <<"Tage zwischen Referenz und eingebenem Datum: "<< dtage << endl;
	
	// wochentag bestimmen
	
	wochentag =  dtage % 7;
	
		switch (wochentag) {	
		case 0 : cout << "Sonntag" ; break ;
	    case 1 : cout << "Montag" ; break ;
	    case 2 : cout << "Dienstag" ; break ;
	    case 3 : cout << "Mittwoch" ; break ;
	    case 4 : cout << "Donnerstag" ; break ;
		case 5 : cout << "Freitag" ; break ;
		case 6 : cout << "Samstag" ; break ;
    }
}


	