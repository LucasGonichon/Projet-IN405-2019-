#ifndef JOUEUR_H
#define JOUEUR_H

#include <navalmap.h>

void attaque (coord_t, navalmap_t);

void bombardier (coord_t, navalmap_t);

void charge (coordt_t, navalmap_t);

void deplacement (coord_t, navalmap_t);

void mine (coordt_t, navalmap_t);

void radar (navalmap_t);

void radarP (navalmap_t);

void reparations (navalmap_t);

#endif