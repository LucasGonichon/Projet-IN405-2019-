#ifndef JOUEUR_H
#define JOUEUR_H

#include <navalmap.h>

// Initialisation d'une carte de jeu
// renvoie la carte de jeu initialisée
jeu * init_jeu (navalmap_t *, int, int);

// Vérifie que le vecteur est bien compris dans la portée
// renvoie 0 si non, 1 si oui
int checkRange (coord_t, int, int);

// Vérifie qu'un vecteur traduit un mouvement rectiligne
// return 1 si oui, 0 si non
int isLinear (coord_t);

// Ajoute un vecteur à une coordonnée
// retourne la nouvelle coordonnée
coord_t newPos (coord_t, coord_t);

// Deplace un bateau d'un vecteur vect
void deplacement (jeu *, int, coord_t);

// Tir sur une case positionnée à un vecteur par rapport au bateau
void attaque (jeu *, int, coord_t);

// Charge en suivant un vecteur
void charge (jeu *, int, coord_t);

// Détecte le bateau le plus proche
// renvoie l'id du bateau détecté, ou -1 si aucun détecté
int radar (jeu *, int);

void reparations ();

#endif