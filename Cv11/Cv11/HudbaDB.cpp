#include "Hudba.h"
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

extern t_album* prvni;

void OnAdd()
{
    char interpret[TEXT_SIZE], nazev[TEXT_SIZE];
    int rok;

    printf("Zadejte nazev alba: ");
    fgets(nazev, TEXT_SIZE, stdin);
    nazev[strcspn(nazev, "\n")] = 0;

    printf("Zadejte interpreta: ");
    fgets(interpret, TEXT_SIZE, stdin);
    interpret[strcspn(interpret, "\n")] = 0;

    printf("Zadejte rok vydani: ");
    scanf("%d", &rok);
    getchar();

    add(interpret, nazev, rok, &prvni);
}

void OnDelete()
{
    int rok;
    printf("Zadejte rok alba pro smazani: ");
    scanf("%d", &rok);
    getchar();

    del(rok, &prvni);
}

void OnPrint()
{
    printList(prvni);
}

void OnRange()
{
    int od, doo;
    printf("Zadejte rozmezi roku od do: ");
    scanf("%d %d", &od, &doo);
    getchar();

    printRange(prvni, od, doo);
}


void add(char* interpret, char* nazev, int rok, t_album** uk_prvni)
{
    t_album* novy = (t_album*)malloc(sizeof(t_album));
    strcpy(novy->interpret, interpret);
    strcpy(novy->nazev, nazev);
    novy->rok = rok;
    novy->dalsi = NULL;

    if (*uk_prvni == NULL) {
        *uk_prvni = novy;
        return;
    }

    if (strcmp(interpret, (*uk_prvni)->interpret) < 0) {
        novy->dalsi = *uk_prvni;
        *uk_prvni = novy;
        return;
    }

    t_album* p = *uk_prvni;
    while (p->dalsi && strcmp(p->dalsi->interpret, interpret) < 0) {
        p = p->dalsi;
    }

    novy->dalsi = p->dalsi;
    p->dalsi = novy;
}

void del(int rok, t_album** uk_prvni)
{
    t_album* p = *uk_prvni;
    t_album* pred = NULL;

    while (p) {
        if (p->rok == rok) {
            if (pred == NULL) *uk_prvni = p->dalsi;
            else pred->dalsi = p->dalsi;

            free(p);
            printf("Zaznam z roku %d smazan.\n", rok);
            return;
        }
        pred = p;
        p = p->dalsi;
    }
    printf("Zadny zaznam z roku %d nebyl nalezen.\n", rok);
}

void printList(t_album* prvni)
{
    printf("\n%-25s %-25s %-5s\n", "Nazev alba", "Interpret", "Rok");
    printf("-------------------------------------------------------------------\n");

    t_album* p = prvni;
    while (p) {
        printf("%-25s %-25s %d\n", p->nazev, p->interpret, p->rok);
        p = p->dalsi;
    }

    printf("\n");
}

void printRange(t_album* prvni, int od, int doo)
{
    int nalezeno = 0;

    t_album* p = prvni;
    while (p) {
        if (p->rok >= od && p->rok <= doo) {
            if (!nalezeno) {
                printf("\n%-25s %-25s %-5s\n", "Nazev alba", "Interpret", "Rok");
                printf("-------------------------------------------------------------------\n");
            }
            printf("%-25s %-25s %d\n", p->nazev, p->interpret, p->rok);
            nalezeno = 1;
        }
        p = p->dalsi;
    }

    if (!nalezeno)
        printf("\nV seznamu neni album vydane od roku %d do roku %d.\n", od, doo);
}
