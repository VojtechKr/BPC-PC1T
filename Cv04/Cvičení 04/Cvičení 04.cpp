// Cvičení 04.cpp : Defines the entry point for the application.
//

#include "Cvičení 04.h"

int jePrestupny ( int rok ) {
	// Rok je prestupny, pokud je delitelny 4, ale neni delitelny 100, nebo je delitelny 400
		if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
			return 1; // Prestupny
	} else {
			return 0; // Neni prestupny
	}
}

int main() {
	// Testujeme roky podle zadani
		int roky[] = { 1000, 2000, 2002, 2012, 2022, 2200 };
		
		for (int i = 0; i < 6; i++) {
			printf("%d %d\n", roky[i], jePrestupny(roky[i]));
		}

	return 0;
}