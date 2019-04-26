#ifndef JOUEUR_H
#define JOUEUR_H

#include <navalmap.h>
#include "mestypes.h"

// Initialisation d'une carte de jeu
// renvoie la carte de jeu initialisée
jeu_t * init_jeu (navalmap_t *, int, int);

// Libération de la mémoire de jeu
void free_jeu (jeu_t *);

// Vérifie que le vecteur est bien compris dans la portée
// renvoie 0 si non, 1 si oui
int checkRange (coord_t, int, int);

// Vérifie qu'un vecteur traduit un mouvement rectiligne
// return 1 si oui, 0 si non
int isLinear (coord_t);

// Vérifie qu'un point est dans limites de la carte
// renvoie 1 si oui, 0 si non
int isInBounds (coord_t, navalmap_t *);

// Ajoute un vecteur à une coordonnée
// retourne la nouvelle coordonnée
coord_t newPos (coord_t, coord_t);

// Transforme un message en action
void doMessage (jeu_t *, int, message);

// Deplace un bateau d'un vecteur vect
void deplacement (jeu_t *, int, coord_t);

// Tir sur une case positionnée à un vecteur par rapport au bateau
void attaque (jeu_t *, int, coord_t);

// Charge en suivant un vecteur
void charge (jeu_t *, int, coord_t);

// Détecte le bateau le plus proche
// renvoie l'id du bateau détecté, ou -1 si aucun détecté
int radar (jeu_t *, int);

// répare le bateau
void reparations (jeu_t *, int);

#endif