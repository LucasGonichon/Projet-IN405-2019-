#ifndef LECTURE_H
#define LECTURE_H

#include "mestypes.h"

// Donne une information lue dans le fichier (un mot)
// paramètres : file descriptor, taille du mot lu
char * getInfo (int fd);

/*
int longeur_fichier (char *);

void lire (char *, int, int, char *);
 */

// lit mot par mot pour renvoyer une jmap
// nbTours est le nombre de tours lu dans le fichier
jeu_t * lire_fichier (int fd, int * nbTours);

#endif
