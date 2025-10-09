// Cvičení 04 čt.cpp : Defines the entry point for the application.
//

#include "Cvičení 04 čt.h"

//Funkce pro zjisteni, zda je rok prestupny
int jePrestupny(int rok) {
	if ((rok % 4 == 0 && rok % 100 != 0) || (rok % 400 == 0)) {
		return 1;
	}
	else {

		return 0;
	}
}
	
int main()
{
	int zacatek, konec;

	//Uzivatelsky vstup
	printf("Zadejte pocatectni rok: ");
	scanf("%d", &zacatek);

	printf("Zadejte koncovy rok: ");
	scanf("%d", &konec);

	printf("\nProgram na prestupny rok\n");
	printf("Rok\t\tPrestupny\n");

	//smycka přes roky
	for (int rok = zacatek; rok <= konec; rok++) {
		printf("%d\t\t%d\n", rok, jePrestupny(rok));
	}
	
	return 0;

}
