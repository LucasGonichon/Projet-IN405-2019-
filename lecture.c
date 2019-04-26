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

  char * tmp = malloc (sizeof (char));
  char * res = malloc (sizeof (char));
  int wordSize = 1;

  while (1) {
      read (fd, tmp, sizeof (char));

      if (tmp[0] == ";" || tmp[0] == " ") break;

      res = realloc (res, sizeof (char) * wordSize);
      res[wordSize-1] = tmp[0];
      wordSize++;
  }

  free (tmp);
  return res;
}

jeu_t * lire_fichier (int fd, int * nbTours) {
  getInfo (fd);
}

/*

int longeur_fichier(char* nomf){
  int taille;
  struct stat etat;
  stat(nomf, &etat);
  taille = (int)etat.st_size;
  return taille;
}

// lire les charactères de début à fin
void lire(char* nomf, int deb, int fin, char * chaine){
  //Ouverture
  int fd;
  char buf;

  fd=open(nomf, O_RDONLY);
  
  for(int i=0;i<deb;i++){
    read(fd, &buf, sizeof(char));
  }

  for(int i=deb;i<fin;i++){
    read(fd, &buf, sizeof(char));
    if(i>=deb){
     chaine[i-deb]=buf;
    }
  }
  close(fd);
}

jeu_t * lire_fichier(char* nomf, int * nbtour){
	int fd, type,tx,ty, nbj, Cmax, Kmax, conteur;
  char buf;
  char * chaine;
  jeu_t * res = NULL;

  fd=open(nomf, O_RDONLY);
  
  for(int l=0;l<longeur_fichier(nomf);++l){
    read(fd, &buf, sizeof(char));
    if(buf==';' || buf=='\n'){
      conteur++;
        switch (conteur) {
        case 1:
          type=l;
			break;
        case 2:
          tx=l;
			break;
        case 3:
          ty=l;
			break;
        case 4:
          nbj=l;
			break;
        case 5:
          Cmax=l;
			break;
        case 6:
          Kmax=l;
			break;
		}
      }
    }
    
  close(fd);
  

  //on remplie inf
  map_t mtype = MAP_RECT;
  
  coord_t size;
  //On récupère la taille x de la carte
  chaine=malloc(sizeof(char)*(tx-type));
  lire(nomf, type+1, tx, chaine);
  size.x = atoi(chaine);
  free(chaine);
  
  //On récupère la taille y de la carte
  chaine=malloc(sizeof(char)*(ty-tx));
  lire(nomf, tx+1, ty, chaine);
  size.y = atoi(chaine);
  free(chaine);
  
  int nbEquipes = 0;
  //On récupère le nommbre de joueurs
  chaine=malloc(sizeof(char)*(nbj-ty));
  lire(nomf, ty+1, nbj, chaine);
  nbEquipes = atoi(chaine);
  free(chaine);
  
  int Cm = 0;
  //On récupère Cmax
  chaine=malloc(sizeof(char)*(Cmax-nbj));
  lire(nomf, nbj+1, Cmax, chaine);
  Cm = atoi(chaine);
  free(chaine);
  
  int Km = 0;
  //On récupère Kmax
  chaine=malloc(sizeof(char)*(Kmax-Cmax));
  lire(nomf, Cmax+1, Kmax, chaine);
  Km = atoi(chaine);
  free(chaine);
  
  //On récupère le nombre de tours
  chaine=malloc(sizeof(char)*(longeur_fichier(nomf)-Kmax));
  lire(nomf, Kmax+1, longeur_fichier(nomf), chaine);
  *nbtour = atoi(chaine);
  free(chaine);

  navalmap_t * nmap = NULL;

  nmap = init_navalmap (mtype, size, nbEquipes);
  placeRemainingShipsAtRandom (nmap);

  res = init_jeu (nmap, Km, Cm);
  
  return res;
}

*/
