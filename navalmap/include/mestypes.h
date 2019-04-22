#ifndef MESTYPES_H
#define MESTYPES_H

#include <navalmap.h>

typedef struct{ //structure qui est retournée par la kecture de fichier
	map_t type;
	coord_t taille;
	int nbequipes;
	int nbjoueurs;
	int cmax;
	int kmax;
	int nbtour;
}info;


typedef struct {
	navalmap_t navalmap;
	int Cmax, Kmax, nbTours;
} game_info;

typedef struct{ //message envoyé par le serveur et les joueurs à travers les pipe
	int action; //action choisi
	int x; //la modification en x qui sera fait
	int y; //la modification en y qui sera fait
}message;

#endif