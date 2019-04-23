//TypeCartes ; TailleX; TailleY
//rectangle ;  1  0  ;  1  0  \n

//nbJoueurs ;Cmax;Kmax;nbTours
//2  ;  1  0  0  ;  1  0  0  ;  2  0 

#include <navalmap.h>
#include <mestypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h> 
#include <sys/stat.h>

/*
char * getInfo (int fd) {

	char * tmp;
	char * res;
	int i = 0;

	if (read (fd, tmp, sizeof (char)) < 1)
		return NULL;
	
	while ( (*tmp == ' ') || (*tmp == '\n') )
		if (read (fd, tmp, sizeof (char)) < 1)
			return NULL;

	while (1) {
		res[i] = *tmp;

		if (read (fd, tmp, sizeof ( char)) < 1)
			return res;
		
		if ( (*tmp == ' ') || (*tmp == '\n') )
			break;

		i++;
	}
	return res;
}

info lire_fichier (char * nomf){
	
	int fd = open (nomf, O_RDONLY);

	info res;

	if (fd > 0) {

		char * map_type = getInfo (fd);

		if (strcmp (map_type, "rectangle") == 0)
			res.type = MAP_RECT;

		res.taille.x = atoi (getInfo (fd));
		res.taille.y = atoi (getInfo (fd));

		res.nbjoueurs = atoi (getInfo (fd));

		res.cmax = atoi (getInfo (fd));
		res.cmax = atoi (getInfo (fd));
		res.nbtour = atoi (getInfo (fd));

		close (fd);
	}

	else {
		printf ("échec du chargement du niveau : %s", nomf);
		exit (1);
	}

	return res;
}
*/

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

  for(int i=0;i<fin;i++){
    read(fd, &buf, sizeof(char));
    if(i>=deb){
     chaine[i-deb]=buf;
    }
  }
  close(fd);
}

info lire_fichier(char* nomf){
	int fd, type,tx,ty, nbj, Cmax, Kmax, conteur;
  char buf;
  char * chaine;
  info inf;

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
    inf.type=MAP_RECT;//tojours rectangle
    
   //On récupère la taille x de la carte
  chaine=malloc(sizeof(char)*(tx));
  lire(nomf, type+1, tx, chaine);
  inf.taille.x = atoi(chaine);
  free(chaine);
  
  //On récupère la taille y de la carte
  chaine=malloc(sizeof(char)*(ty));
  lire(nomf, tx+1, ty, chaine);
  inf.taille.y = atoi(chaine);
  free(chaine);
  
  //On récupère le nommbre de joueurs
  chaine=malloc(sizeof(char)*(nbj));
  lire(nomf, ty+1, nbj, chaine);
  inf.nbequipes = atoi(chaine);
  free(chaine);
  
  //On récupère Cmax
  chaine=malloc(sizeof(char)*(Cmax));
  lire(nomf, nbj+1, Cmax, chaine);
  inf.cmax = atoi(chaine);
  free(chaine);
  
  //On récupère Kmax
  chaine=malloc(sizeof(char)*(Kmax));
  lire(nomf, Cmax+1, Kmax, chaine);
  inf.kmax = atoi(chaine);
  free(chaine);
  
  //On récupère le nombre de tours
  chaine=malloc(sizeof(char)*(longeur_fichier(nomf)));
  lire(nomf, Kmax+1, longeur_fichier(nomf), chaine);
  inf.nbtour = atoi(chaine);
  free(chaine);
  
  printf("%d,,%d,,%d,,%d",inf.taille.y,inf.taille.x,inf.cmax,inf.nbtour);
  return inf;
}
