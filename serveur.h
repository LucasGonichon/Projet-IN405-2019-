#ifndef SERVEUR_H
#define SERVEUR_H

#include "mestypes.h"
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct {//structure des pipe
    int cote[2];
} t_pipe;

int joueur (int, t_pipe);

int jeu(jeu_t *, int);//fonction qui lance le serveur

#endif
