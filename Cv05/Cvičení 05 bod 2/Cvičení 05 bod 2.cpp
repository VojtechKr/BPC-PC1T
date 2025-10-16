// Cvičení 05 bod 2.cpp : Defines the entry point for the application.
//

#include "Cvičení 05 bod 2.h"

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
	return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}

void vektorovySoucin(double a[3], double b[3], double c[3]) {
	c[0] = a[1] * b[2] - a[2] * b[1];
	c[1] = a[2] * b[0] - a[0] * b[2];
	c[2] = a[0] * b[1] - a[1] * b[0];
}

int main()
{
	double a[3], b[3], c[3], vektSoucin[3];

	printf("Vektor A (3 hodnoty oddelene carkou) ");
	scanf("%lf,%lf,%lf", &a[0], &a[1], &a[2]);

	printf("Vektor B (3 hodnoty oddelene carkou) ");
	scanf("%lf,%lf,%lf", &b[0], &b[1], &b[2]);


	soucet(a, b, c);
	double velikostA = velikost(a);	
	double skalarni = skalarniSoucin(a, b);
	vektorovySoucin(a, b, vektSoucin);


	printf("Soucet A + B je: (%.6f, %.6f, %.6f)\n", c[0], c[1], c[2]);
	printf("Velikost A je: %.6f\n", velikostA);
	printf("Skalarni soucin A*B je: %.6f\n", skalarni);
	printf("Vektorovy soucin A x B je: (%.6f, %.6f, %.6f)\n", vektSoucin[0], vektSoucin[1], vektSoucin[2]);


	return 0;
}
