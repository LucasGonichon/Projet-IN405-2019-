//TypeCartes ; TailleX; TailleY
//rectangle ;  1  0  ;  1  0  \n

//nbJoueurs ;Cmax;Kmax;nbTours
//2  ;  1  0  0  ;  1  0  0  ;  2  0 

#include <navalmap.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	navalmap_t navalmap;
	int Cmax, Kmax, nbTours;
} game_info;

game_info lire_fichier(char* nomf){
	
	FILE * f = fopen (nomf, "r");

	game_info res;

	if (f != NULL) {

		navalmap_t * navalmap;

		char * type_carte;
		fscanf (f, "%s", type_carte);

		coord_t size;
		fscanf (f, "%d %d", &size.x, &size.y);

		int nbShips;
		fscanf (f, "%d", &nbShips);

		if (strcmp (type_carte, "rectangle") == 0)
			navalmap = init_navalmap (MAP_RECT, size, nbShips);

		else {
			printf ("type de carte invalide");
			exit (1);
		}

		fscanf (f, "%d %d %d", &res.Cmax, &res.Kmax, &res.nbTours);

		res.navalmap = *navalmap;

		fclose (f);
	}

	else {
		printf ("échec du chargement du niveau : %s", nomf);
		exit (1);
	}

	return res;
}