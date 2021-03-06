#include <navalmap.h>
#include <stdlib.h>
#include <math.h>
#include "mestypes.h"
#include "joueur.h"
#include <math.h>
#include <stdio.h>

jeu_t * init_jeu (navalmap_t * nmap, int Kmax, int Cmax) {

    jeu_t * res = malloc (sizeof (nmap));

    res->nmap = nmap;
    res->shipK = malloc (nmap->nbShips * sizeof (int));
    res->shipC = malloc (nmap->nbShips * sizeof (int));

    for (int i = 0; i < nmap->nbShips; i++) {
        res->shipK[i] = Kmax;
        res->shipC[i] = Cmax;
    }

    return res;
}

void free_jeu (jeu_t * jmap) {
    free_navalmap (jmap->nmap);
    free (jmap->shipC);
    free (jmap->shipK);
    free (jmap);
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

int isInBounds (coord_t pos, navalmap_t * nmap) {
    if (pos.x < 0 || pos.x >= nmap->size.x)
        return 0;
    if (pos.y < 0 || pos.y >= nmap->size.y)
        return 0;
    return 1;
}

coord_t newPos (coord_t pos, coord_t vect) {
    pos.x += vect.x;
    pos.y += vect.y;
    return pos;
}

void doMessage (jeu_t * jmap, int shipID, message order) {
    coord_t vect;
    vect.x = order.x;
    vect.y = order.y;
    if (order.action == ATK) {
        attaque (jmap, shipID, vect);
        printf ("Le bateau %d tir vers %d %d\n", shipID, vect.x, vect.y);
    }else if (order.action == MOV) {
        deplacement (jmap, shipID, vect);
        printf ("Le bateau %d se déplace vers %d %d\n", shipID, vect.x, vect.y);
    }else {
        printf ("Le bateau %d ne fait rien !\n", shipID);
    }
}

void deplacement (jeu_t * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 1, 2)) {
        jmap->shipK[shipID] -= 2;
        moveShip (jmap->nmap, shipID, vect);
    }
}

void attaque (jeu_t * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 2, 4) && isInBounds (newPos (jmap->nmap->shipPosition[shipID], vect), jmap->nmap)) {
        jmap->shipK[shipID] -= 5;
        int nbFoundShips = 0;
        int * buff = malloc (jmap->nmap->size.x * jmap->nmap->size.y * sizeof (int));
        buff = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 1, &nbFoundShips);
        int * listID = malloc (nbFoundShips * sizeof (int));

        for (int i = 0; i < nbFoundShips; i++) {
            listID[i] = buff[i];
        }

        free (buff);

        if (listID != NULL)
            for (int i = 0; i < nbFoundShips; i++) {
                jmap->shipC[listID[i]] -= 20;
            }
        
        free (listID);

        int * IDcentre = malloc (sizeof (int));
        IDcentre = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 0, &nbFoundShips);
        
        if (IDcentre != NULL)
            jmap->shipC[*IDcentre] -= 20;

        free (IDcentre);
    }
}

void charge (jeu_t * jmap, int shipID, coord_t vect) {
    if (checkRange (vect, 4, 5) && isLinear (vect) && isInBounds (newPos (jmap->nmap->shipPosition[shipID], vect), jmap->nmap)) {
        //On applique les dégats sur la case touchée et sur l'attaquant
        int * IDcentre = malloc (sizeof (int));
        int foundShips = 0;
        IDcentre = rect_getTargets (jmap->nmap, newPos (jmap->nmap->shipPosition[shipID], vect), 0, &foundShips);
        
        if (IDcentre != NULL) {
            jmap->shipC[*IDcentre] -= 50;
            jmap->shipC[shipID] -= 5;
        }
        free (IDcentre);

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

int radar (jeu_t * jmap, int shipID) {
    jmap->shipK[shipID] -= 3;
    int nbFoundShips = 0;
    int * listID = rect_getTargets (jmap->nmap, jmap->nmap->shipPosition[shipID], fmax (jmap->nmap->size.x, jmap->nmap->size.y), &nbFoundShips);
    if (listID != NULL)
        return *listID;
    return -1;
}

void reparations (jeu_t * jmap, int shipID) {
    if (jmap->shipK[shipID] >= 20) {
        jmap->shipC[shipID] =+ 25;
        jmap->shipK[shipID] -= 20;
    }
}