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