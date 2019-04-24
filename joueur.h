#ifndef JOUEUR_H
#define JOUEUR_H

#include <navalmap.h>

void attaque (player p, coord_t, navalmap_t);

void charge (player p, coordt_t, navalmap_t);

void deplacement (player p, coord_t, navalmap_t);

void radar (player p, navalmap_t);

void reparations (player p, navalmap_t);

#endif