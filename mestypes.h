#ifndef MESTYPES_H
#define MESTYPES_H

#include <navalmap.h>
#define ATK 1
#define MOV 2

typedef struct{ //structure qui est retournée par la kecture de fichier
	map_t type;
	coord_t taille;
	int nbequipes;
	int nbjoueurs;
	int cmax;
	int kmax;
	int nbtour;
}info;

typedef struct{ //message envoyé par le serveur et les joueurs à travers les pipe
	int action; //action choisi
	int x; //la modification en x qui sera fait
	int y; //la modification en y qui sera fait
}message;

typedef struct{
	navalmap_t * nmap;
	int * shipK;
	int * shipC;
}jeu_t;

#endif