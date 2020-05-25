//Implementierung des Gauss Algorithmus zur Lösung von LGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>
#include <cstdlib>

using namespace std;

int main() {

// Variablen

char fname[30] = "a13-lgs2.dat";
char pivot;
int max = 10;
int n;
double A[max][max]; 
double b[max];
double x[max]; 
double l[max]; 


		// Einlesen der Matrix
 
	ifstream dfile(fname) ;
		if(!dfile) 
		{
		cout << "Datei nicht gefunden" << endl ;
		exit(1) ;
		}
		
		dfile >> n ;
		
				// Variablen speichern
				
		// Matrix 	A
    for(int i=0; i<n; i++){
		for( int j=0; j<n; j++){
	    dfile >> A[i][j] ;
		}
	}
		// Vektor 	b
    for(int i=0; i<n; i++) {
		dfile >> b[i] ;
	}
    dfile.close() ;
	
		// Hilfsvektor l
	for(int i=0; i<n; i++) {
		l[i] = b[i] ;
	}
	
				// LGS ausgeben
	cout << "A | b " << endl;
	for( int i = 0; i < n; i++)
	{
		cout << "|";
		for( int j = 0; j < n; j++)
		{
			cout << setw(8) << setprecision(3) << A[i][j];
		}
			cout << "| " << setw(6) << b[i]; " |";
		cout << endl;
	}
	cout << endl;
	
			// Entscheidung ob Pivot oder nicht
	cout << " Soll Pivot verwendet werden (j/n) ?" << endl;
	cin >> pivot;
	
	if(pivot == n){
		
			// Matrix auf Dreicksform bringen
		for ( int i = 0; i < n ; i++) 
		{
			for( int j=i+1; j < n; j++) // alles links der hauptdiagonale zu 0 (prinzipiell aus VL übernommen)
			{
				double a = A[i][j] / A[i][i];
				for (int k = i; k<n; k++)
				{
				A[j][k] = A[j][k] - a * A[i][k];
				}
			l[j] = l[j] - a * l[i];
			}
		}
	}else 
	{
			// Betragsgrößtes Element suchen - Pivot suche durchführen
		for(int i = 0 ; i < n; i++) 
		{
			int m = i; // soll größtes Element sein
			
			for(int j = i+1; j < n; j++)
			{
				if(abs(A[j][i]) > abs(A[m][i]))				
				{
					m = j;
				}
		
			// Zeilen tauschen
			for(int j = 0; j < n; j++)
			{	
				double X = A[i][j];
				A[i][j] = A[m][j]; 
				A[m][j] = X;	
			}
				double y = l[i]; 
				l[i] = l[m]; 
				l[m] = y;
			}
		}
		
		for ( int i = 0; i < n ; i++) 
		{
			for( int j=i+1; j < n; j++)
			{
				double a = A[j][i] / A[i][i];
				for (int k = i; k<n; k++)
				{
				A[j][k] = A[j][k] - a * A[i][k];
				}
			l[j] = l[j] - a * l[i];
			}
		}
		
	}
			// Dreicksform ausgeben
	cout << "Gauss" << endl;
		for( int i = 0; i < n; i++)
		{
		cout << "|";
		for( int j = 0; j < n; j++)
		{
			cout << setw(8)  << setprecision(4) << int(A[i][j]); // Hier passieren Rundungsfehler!!
		}
		cout << "| " << setw(8) << setprecision(5) << int(l[i]); " |"; // Hier könnten Rundungsfehler passieren
		cout << endl;
	} cout << endl;
	
			// Lösungsvektor x bestimmen und ausgeben
	for(int i=n-1; i>=0; i--)
    {
	x[i] = l[i] ;
	for( int j=i+1; j<n; j++)
	    x[i] = x[i] - A[i][j]*x[j] ;
		x[i] = x[i] / A[i][i] ;
    }

    cout << "x =  " << endl ;
    cout << "| " ;
    for( int i=0; i<n; i++)
    {
	cout << setw(6) << x[i] ;
    }
    cout << " |" << endl ;
	
	return 0;
}