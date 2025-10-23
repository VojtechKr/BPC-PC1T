// Cv06.cpp : Defines the entry point for the application.
//

#include "Cv06.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

using namespace std;


int PocetPismen(char* text);
int PocetCislic(char* text);
int DelkySlov(char* text, int* delky);


int main() {
	char text[] = "Toto jsou 2 vzorove vety, ktere budou zpracovavany Vasemi funkcemi. Auto Hyundai ix35 ma pres 120 konskych sil.";
	int delky[100];

	printf("Dany textovy retezec: \n%s\n", text);

	int pocetPismen = PocetPismen(text);
	int pocetCislic = PocetCislic(text);
	int pocetSlov = DelkySlov(text, delky);

	printf("\nPocet pismen v danem retezci: %d\n", pocetPismen);
	printf("Pocet cislic v danem retezci: %d\n", pocetCislic);
	printf("Pocet slov je %d\n", pocetSlov);

	printf("Delky slov jsou: ");
	for (int i = 0; i < pocetSlov; i++) {
		printf("%d ", delky[i]);
		if (i < pocetSlov - 1) printf(", ");
	}
	printf("\n");

	return 0;
}

int PocetPismen(char* text) {
	int count = 0;
	while (*text) {
		if (isalpha((unsigned char)*text)) count++;
		text++;
	}
	return count;
}

int PocetCislic(char* text) {
	int count = 0;
	while (*text) {
		if (isdigit((unsigned char)*text)) count++;
		text++;
	}
	return count;
}

int DelkySlov(char* text, int* delky) {
	int i = 0, delka = 0, pocetSlov = 0;
	while (*text) {
		if (isalpha((unsigned char)*text) || isdigit((unsigned char)*text)) {
			delka++;
		} else if (delka > 0) {
			delky[pocetSlov++] = delka;
			delka = 0;
		}
		text++;
	}
	if (delka > 0) delky[pocetSlov++] = delka;
	return pocetSlov;

}