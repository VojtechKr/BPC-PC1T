// CMakeProject1.cpp : Defines the entry point for the application.
//

#include "CMakeProject1.h"

using namespace std;

void soucet(double a[3], double b[3], double c[3]) {
	for (int i = 0; i < 3; i++) {
		c[i] = a[i] + b[i];
	}
}

double velikost(double a[3]) {
	return sqrt(a[0] * a[0] + a[1] * a[1] + a[2] * a[2]);
}


double skalarniSoucin(double a[3], double b[3]) {
	return a[0]*b[0] + a[1]*b[1] + a[2]*b[2];
}


int main()
{
	double a[3], b[3], c[3];

	cout << "Vektor A (3 hodnoty oddelene carkou); ";
		char sep;
	cin >> a[0] >> sep >> a[1] >> sep >> a[2];

	cout << "Vektor B (3 hodnoty oddelene carkou) ";
	cin >> b[0] >> sep >> b[1] >> sep >> b[2];


	soucet(a, b, c);
	cout << "Soucet vektoru A+B je: (" << c[0] << ", " << c[1] << ", " << c[2] << ")" << endl;


	cout << "Velikost vektoru A je: " << velikost(a) << endl;

	cout << "Skalarni soucin A*B je: " << skalarniSoucin(a,b) << endl;


	return 0;
}