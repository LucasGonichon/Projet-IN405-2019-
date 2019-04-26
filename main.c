#include "affichage.h"
#include "serveur.h"
#include "lecture.h"
#include "joueur.h"
#include "mestypes.h"

int main (int argc, char** argv) {

	if (argc != 2) {
		printf ("erreur de commande !");
		exit (1);
	}

	int * nbTours = malloc (sizeof (int));
	jeu_t * jmap = lire_fichier (argv[1], nbTours);
/*
    init_graphics(TAILLE * jmap->nmap->size.x, TAILLE * jmap->nmap->size.y);
    affiche_auto_off();
    affiche_map (jmap->nmap);
    affiche_all();

	//lancer le jeu
	int try = jeu(jmap, *nbTours);

	wait_escape();

	free_jeu (jmap);
*/
    exit(0);
}
