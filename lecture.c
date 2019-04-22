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

	char c;

	read (fd, &c, sizeof(c));

	if (c == ';')
		return '\0';
	
	return strcat (&c,getInfo(fd));
}

game_info lire_fichier (char * nomf){
	
	int fd = open (nomf, O_RDONLY);

	game_info res;

	if (fd > 0) {

		char * map_type = getInfo (fd);
		map_t type;

		if (strcmp (map_type, "rectangle") == 0)
			type = MAP_RECT;

		res.navalmap.initEntityMap (&res.navalmap);

		coord_t coord = {atoi (getInfo (fd)), atoi (getInfo (fd))};

		res.navalmap = *init_navalmap (type, coord, atoi (getInfo (fd)));

		placeRemainingShipsAtRandom (&res.navalmap);

		res.Cmax = atoi (getInfo (fd));
		res.Kmax = atoi (getInfo (fd));
		res.nbTours = atoi (getInfo (fd));

		close (fd);
	}

	else {
		printf ("échec du chargement du niveau : %s", nomf);
		exit (1);
	}

	return res;
}