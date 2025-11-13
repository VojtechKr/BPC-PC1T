

#include "VectorMath.h"
#include <stdio.h>
#include <math.h>

struct vector3d operace(enum typOperace typ) {
    struct vector3d u = { 0 }, v = { 0 }, vysl = { 0 };
    double skalarni = 0.0;
    double velikostU = 0.0, velikostV = 0.0;

    // Zadávání vektorů
    if (typ == velikostVektoru) {
        printf("Zadejte vektor u (hodnoty x, y, z oddelene carkou): ");
        scanf("%lf,%lf,%lf", &u.x, &u.y, &u.z);
    }
    else {
        printf("Zadejte vektor u (hodnoty x, y, z oddelene carkou): ");
        scanf("%lf,%lf,%lf", &u.x, &u.y, &u.z);
        printf("Zadejte vektor v (hodnoty x, y, z oddelene carkou): ");
        scanf("%lf,%lf,%lf", &v.x, &v.y, &v.z);
    }

    switch (typ) {
    case soucet:
        vysl.x = u.x + v.x;
        vysl.y = u.y + v.y;
        vysl.z = u.z + v.z;
        tisk(vysl, typ);
        break;

    case vektorovySoucin:
        vysl.x = u.y * v.z - u.z * v.y;
        vysl.y = u.z * v.x - u.x * v.z;
        vysl.z = u.x * v.y - u.y * v.x;
        tisk(vysl, typ);
        break;

    case skalarniSoucin:
        skalarni = u.x * v.x + u.y * v.y + u.z * v.z;
        vysl.x = skalarni;
        tisk(vysl, typ);
        break;

    case velikostVektoru:
        vysl.x = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
        tisk(vysl, typ);
        break;

    case porovnaniVektoru:
        velikostU = sqrt(u.x * u.x + u.y * u.y + u.z * u.z);
        velikostV = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);

        if (fabs(velikostU - velikostV) < 1e-9)
            printf("\n|u| = |v|\n");
        else if (velikostU > velikostV)
            printf("\n|u| > |v|\n");
        else
            printf("\n|u| < |v|\n");
        break;
    }

    return vysl;
}

void tisk(struct vector3d vysl, enum typOperace typ) {
    switch (typ) {
    case soucet:
        printf("\nSoučet vektoru u a v je: (%.2f, %.2f, %.2f)\n", vysl.x, vysl.y, vysl.z);
        break;
    case vektorovySoucin:
        printf("\nVektorovy soucin vektoru u a v je: (%.2f, %.2f, %.2f)\n", vysl.x, vysl.y, vysl.z);
        break;
    case skalarniSoucin:
        printf("\nSkalarni soucin vektoru u a v je: %.2f\n", vysl.x);
        break;
    case velikostVektoru:
        printf("\nVelikost vektoru je: [%.2f]\n", vysl.x);
        break;
    default:
        break;
    }
}
