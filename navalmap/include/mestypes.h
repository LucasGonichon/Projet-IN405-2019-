#include <navalmap.h>

typedef struct{
	map_t type;
	coord_t taille;
	int nbequipes;
	int nbjoueurs;
	int cmax;
	int kmax;
	int nbtour;
}info;

typedef struct{
	int action;
	int x;
	int y;
}message;
