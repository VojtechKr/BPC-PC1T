#include "Hudba.h"
#include "HudbaDB.h"
#include <stdio.h>
#include <ctype.h>

t_album* prvni = NULL;

int main()
{
    char volba;

    do {
        printf("\nA: Pridat   D: Smazat   P: Tisk   R: Rok od/do   Q: Konec\n");
        printf("> ");

        volba = getchar();
        getchar();  // odmazání enteru

        volba = toupper(volba);

        switch (volba) {
        case 'A': OnAdd(); break;
        case 'D': OnDelete(); break;
        case 'P': OnPrint(); break;
        case 'R': OnRange(); break;
        case 'Q': break;
        default: printf("Neplatna volba.\n");
        }
    } while (volba != 'Q');

    return 0;
}
