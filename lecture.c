//TypeCartes ; TailleX; TailleY
//rectangle ;  1  0  ;  1  0  \n

//nbJoueurs ;Cmax;Kmax;nbTours
//2  ;  1  0  0  ;  1  0  0  ;  2  0 

#include <navalmap.h>
#include "mestypes.h"
#include "joueur.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h>


char * getInfo (int fd) {

  char tmp;
  char * res = malloc (sizeof (char));
  int wordSize = 1;

  while (read (fd, &tmp, sizeof (char)) > 0) {

      if (tmp == ';' || tmp == ' ' || tmp == '\n')
        return res;

      res = realloc (res, sizeof (char) * wordSize);
      res[wordSize-1] = tmp;
      wordSize++;
  }

  return res;
}

jeu_t * lire_fichier (char * nomf, int * nbTours) {

  // alloc et open
  char ** tmp = malloc (sizeof (char *) * 7);

  int fd = open (nomf, O_RDONLY);

  if (fd < 0)
    perror ("erreur d'ouverture");

  else {
    // On récupère les infos (8 infos, car on ignore la 4e (tmp[3]), qui est vide)
    for (int i = 0; i < 8; i++) {
      tmp[i] = malloc (sizeof (char) * 10);
      tmp[i] = getInfo (fd);
        printf ("%d : %d\n", i, atoi (tmp[i]));
    }

    // init nmap
    coord_t size;
    size.x = atoi (tmp[1]);
    size.y = atoi (tmp[2]);
    navalmap_t * nmap = init_navalmap (MAP_RECT, size, atoi (tmp[4]));
    placeRemainingShipsAtRandom (nmap);

    // init jmap
    jeu_t * jmap = init_jeu (nmap, atoi (tmp[6]), atoi (tmp[5]));
    nbTours[0] = atoi (tmp[7]);

    // free et close
    for (int i = 0; i < 10; i++) {
      free (tmp[i]);
    }
    free (tmp);
    close (fd);

    // On return la jmap
    return jmap;
  }

  free (tmp);
  return NULL;
}
