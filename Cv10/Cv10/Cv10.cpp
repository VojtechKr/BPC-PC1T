// Cv10.cpp : Defines the entry point for the application.
//

#include <stdio.h>
#include <ctype.h>

int main() {
    const char* filename_in = "vstup.txt";
    const char* filename_out = "vysledky.txt";

    FILE* fin = fopen(filename_in, "r");
    if (!fin) {
        printf("Chyba: Soubor '%s' se nepodarilo otevrit.\n", filename_in);
        return 1;
    }

    FILE* fout = fopen(filename_out, "w");
    if (!fout) {
        printf("Chyba: Soubor '%s' se nepodarilo vytvorit.\n", filename_out);
        fclose(fin);
        return 1;
    }

    printf("Cteni textu ze souboru\n\n");
    printf("Soubor: %s\nObsahuje:\n", filename_in);

    fprintf(fout, "Cteni textu ze souboru\n\n");
    fprintf(fout, "Vstupni soubor obsahuje:\n");

    int letters = 0, digits = 0;
    int ch;


    while ((ch = fgetc(fin)) != EOF) {
        putchar(ch);     
        fputc(ch, fout); 

        if (isalpha(ch)) letters++;
        if (isdigit(ch)) digits++;
    }

    fclose(fin);


    char hledany;
    printf("\nZadejte libovolny znak: ");
    scanf(" %c", &hledany);

  
    fin = fopen(filename_in, "r");
    if (!fin) {
        printf("Chyba: Soubor '%s' se nepodarilo znovu otevrit.\n", filename_in);
        return 1;
    }

    int count = 0;
    while ((ch = fgetc(fin)) != EOF) {
        if (ch == hledany) count++;
    }
    fclose(fin);

  
    printf("\nStatistika souboru: %s\n", filename_in);
    printf("Pocet pismen v textu: %d\n", letters);
    printf("Pocet cislic v textu: %d\n", digits);
    printf("Pocet vyskytu znaku '%c': %d\n", hledany, count);

    fprintf(fout, "\nStatistika souboru: %s\n", filename_in);
    fprintf(fout, "Pocet pismen v textu: %d\n", letters);
    fprintf(fout, "Pocet cislic v textu: %d\n", digits);
    fprintf(fout, "Pocet vyskytu znaku '%c': %d\n", hledany, count);

    fclose(fout);

    return 0;
}
