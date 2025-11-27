#pragma once
#include <stdio.h>

#define TEXT_SIZE 50

typedef struct t_album {
    char interpret[TEXT_SIZE];
    char nazev[TEXT_SIZE];
    int rok;
    struct t_album* dalsi;
} t_album;

// operace
void add(char* interpret, char* nazev, int rok, t_album** uk_prvni);
void del(int rok, t_album** uk_prvni);
void printList(t_album* prvni);
void printRange(t_album* prvni, int od, int doo);

