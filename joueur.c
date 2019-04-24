#include <navalmap.h>
#include <stdlib.h>
#include <math.h>
#include <mestypes.h>
#include <math.h>

/*
//navire : nmap->map [nmap->shipPosition [shipID] .y][nmap->shipPosition [shipID] .x]

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
player * getPlayer (navalmap_t * nmap, coord_t pos) {
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
    coord_t vect = {nmap->shipPosition [p.shipID].x - target.x, nmap->shipPosition [p.shipID].y - target.y}

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

*/

jeu * init_jeu (navalmap_t * nmap, int Kmax, int Cmax) {

    jeu * res = malloc (sizeof (jeu));

    res->nmap = nmap;
    res->shipK = malloc (nmap->nbShips * sizeof (int));
    res->shipC = malloc (nmap->nbShips * sizeof (int));

    for (int i = 0; i < nmap->nbShips; i++) {
        res->shipK[i] = Kmax;
        res->shipC[i] = Cmax;
    }

    return res;
}

int checkRange (coord_t vect, int min, int max) {
    if (vect.x < min)
        return 0;
    if (vect.y < min)
        return 0;
    if (vect.x > max)
        return 0;
    if (vect.y > max)
        return 0;
    return 1;
}

int isLinear (coord_t vect) {
    if (vect.x == 0)
        return 1;
    if (vect.y == 0)
        return 1;
    return 0;
}

void deplacement (jeu * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 1, 2)) {
        jmap->shipK[shipID] -= 2;
        moveShip (jmap->nmap, shipID, vect);
    }
}

coord_t newPos (coord_t pos, coord_t vect) {
    pos.x += vect.x;
    pos.y += vect.y;
    return pos;
}

void attaque (jeu * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 2, 4)) {
        jmap->shipK[shipID] -= 5;
        int nbFoundShips = 0;
        int * tmp = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 1, &nbFoundShips);
        int * listID = malloc (nbFoundShips * sizeof (int));
        listID = tmp;

        if (listID != NULL)
            for (int i = 0; i < nbFoundShips; i++) {
                jmap->shipC[listID[i]] -= 20;
            }

        int * IDcentre;
        IDcentre = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 0, &nbFoundShips);
        
        if (IDcentre != NULL)
            jmap->shipC[*IDcentre] -= 20;
    }
}

void charge (jeu * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 4, 5) || isLinear (vect)) {
        //On applique les dégats sur la case touchée et sur l'attaquant
        int * IDcentre;
        int foundShips = 0;
        IDcentre = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 0, &foundShips);
        
        if (IDcentre != NULL) {
            jmap->shipC[*IDcentre] -= 50;
            jmap->shipC[shipID] -= 5;
        }

        //Le bateau s'arrete une case avant la case touchée
        jmap->shipK[shipID] -= 3;
        coord_t modVect = vect;
        if (modVect.x != 0)
            modVect.x -= (modVect.x/modVect.x);
        if (modVect.y != 0)
            modVect.y -= (modVect.y/modVect.y);
        moveShip (jmap->nmap, shipID, modVect);        
    }
}

int radar (jeu * jmap, int shipID) {
    jmap->shipK[shipID] -= 3;
    int nbFoundShips = 0;
    int * listID = rect_getTargets (jmap->nmap, jmap->nmap->shipPosition[shipID], fmax (jmap->nmap->size.x, jmap->nmap->size.y), &nbFoundShips);
    if (listID != NULL)
        return *listID;
    return -1;
}

void reparations (jeu * jmap, int shipID) {
    jmap->shipC[shipID] =+ 25;
    jmap->shipK[shipID] -= 20;
}