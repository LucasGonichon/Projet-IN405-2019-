#ifndef MESTYPES_H
#define MESTYPES_H

#include <navalmap.h>

typedef struct{
	map_t type;
	coord_t taille;
	int nbjoueurs;
	int cmax;
	int kmax;
	int nbtour;
}info;


typedef struct {
	navalmap_t navalmap;
	int Cmax, Kmax, nbTours;
} game_info;

#endif