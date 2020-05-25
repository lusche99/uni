// aufgabe 11 - erzielte Tore

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

int main()
{  

	int data[11][7] = {0};
	int goals[7] = {0};
	int champ = 0;
	
    // daten einlesen 
	
	ifstream fin("data.sec");
	
	// evtl Fehler ausgabe
	
	if (not fin)
	{
			cout << "Datei nicht gefunden" << endl;
			exit(1);
	}
	
	// matrix füllen
	
	for (int j = 0; j < 7; j++){
        for (int i = 0; i < 11; i++) {
            fin >> data[i][j];
             }
    }
	
	// daten bearbeiten
	
	// Torsummen und bestes team ermitteln 
	
	for(int i = 0; i<7 ; i++)
	{
		for ( int j = 1; j<11 ; j++)
		{
			goals[i] += data[j][i];
		}if(goals [i] > goals[champ] )
		{	
		champ = i;
		}
	}
	
	// Ausgabe der Tabelle
	
	cout << "Team---------------------------------Tore-Meister" <<endl;
	
	 for (int i = 0; i < 7; i++)
    {
        for (int j = 0; j < 11; j++)
            cout << setw(3) << data[j][i];
        cout << setw(6) << goals[i];
        if (goals[i] == goals[champ]) cout << "  champion";
        cout << endl;
    }

    cout << endl;
	
	
	fin.close();
	system("PAUSE");
    return 0;
}

