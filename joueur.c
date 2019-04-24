#include <navalmap.h>
#include <math.h>
#include "mestypes.h"

navire : nmap->map [nmap->shipPosition [shipID] .y][nmap->shipPosition [shipID] .x]

//Joueurs de la partie
player * pList;

// calcul de portee
// return 1 si à portée, 0 sinon
int isInRange (coord_t A, coord_t B, int range) {
    if (sqrt (((B.x - A.x)*(B.x - A.x)) + ((B.y - A.y)*(B.y - A.y))) <= range)
        return 1;
    return 0;
}

// Renvoie la struct "player" correspondante à l'id du bateau aux coordonnées pos
// Si aucun bateau, alors renvoie NULL
player * getPlayer (navalmap * nmap, coord_t pos) {
    entityid_t tmp = nmap->map [pos.x][pos.y];
    
    for (int i = 0; pList[i] != NULL; i++) {
        if ( (tmp.type == ENT_SHIP) && (tmp.id == p.shipID) )
            return pList[i];
    }

    return NULL;
}

void attaque (player p, coord_t target, navalmap_t * nmap) {
    if (isInRange (nmap->map [nmap->shipPosition [p.shipID] .y][nmap->shipPosition [p.shipID] .x], target, 4))
        if ((player * p = getPlayer (nmap, target)) != NULL)
            p.C--;
}

void deplacement (player p, coord_t target, navalmap_t * nmap) {
    coord_t vect = nmap->map [nmap->shipPosition [p.shipID] .y][nmap->shipPosition [p.shipID] .x] - target;
    if (isInRange (nmap->map [nmap->shipPosition [p.shipID] .y][nmap->shipPosition [p.shipID] .x], target, 2))
        moveShip (nmap, p.shipID, vect);
}

void charge (player p, coord_t target, navalmap_t * nmap) {
    coord_t vect = nmap->map [nmap->shipPosition [p.shipID] .y][nmap->shipPosition [p.shipID] .x] - target;
    if (vect.x == 0) {
        if (isInRange (nmap->map [nmap->shipPosition [p.shipID] .y][nmap->shipPosition [p.shipID] .x], target, 5)) {
            
        }
            
    }
    else if (vect.y == 0) {

    }
    else
        printf ("charge impossible à ces coordonnees !");
}

void radar () {

}

void reparations () {

}