

#pragma once
#include <stdio.h>

enum typOperace { 
    soucet = 1,
    vektorovySoucin,
	skalarniSoucin,
	velikostVektoru,
	porovnaniVektoru,
};

struct vector3d {
    double x;
    double y;
    double z;
};

struct vector3d operace(enum typOperace typ);
void tisk(struct vector3d vysl, enum typOperace typ);
