#include<iostream>
#include<math.h>
#include<stdlib.h>
#include<time.h>

using namespace std;
int main()
{

	double x = 0,y = 0,n = 0, treffer = 0;
	
	cout << "Eingabe von N" << endl << "Enter N: ";
	cin >> n;
	  
	srand((unsigned int)time(0));
	
		for(int i=0;i<n;i++)
		{
			x=double(rand())/double(RAND_MAX); //Zufallszahlen erzeugen
			y=double(rand())/double(RAND_MAX);
				if(pow(x,2) + pow(y,2) <= 1) // Bedingung
				{
				treffer++; 
				}
		}	
	
	cout<<"pi = "<<4*treffer/n<<endl;
	cout<<"treffer innen " << treffer << endl;
	cout<<"treffer aussen " << n - treffer << endl; 
}
