#include <iostream>
#include <cmath>

using namespace std;


int main() {
	double x,y,z,m;

cout <<"Bitte drei verschiedene Zahlen angeben, die nach Groeße sortiert werden sollen: ";
cin >> x;
cin >> y;
cin >> z;

if (( x < y && z < x) || ( y < x && x < z)){	
	m = x;
} else if (( x < z && z < y) || ( y < z && z < x)) {
	m = z;
} else if ((y < z && y > x) || ( z < y && y < x)){
	m = y ;
}
cout <<"Die mittlere Zahl ist :"<< m << endl;

return 0;
	}