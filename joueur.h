#ifndef JOUEUR_H
#define JOUEUR_H

#include <navalmap.h>

void attaque (entityid_t, coord_t, navalmap_t);

void charge (entityid_t, coordt_t, navalmap_t);

void deplacement (entityid_t, coord_t, navalmap_t);

void radar (entityid_t, navalmap_t);

void reparations (entityid_t, navalmap_t);

#endif