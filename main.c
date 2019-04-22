#include "affichage.h"
#include "serveur.h"

int main (int argc, char** argv) {

	//initialisation
    navalmap_t * map;
    coord_t mapsize = {10,10};
    map = init_navalmap (MAP_RECT,mapsize,2);
    init_graphics(TAILLE*map->size.x,TAILLE*map->size.x);
    affiche_auto_off();
    
    //affichage
    affiche_map (map);
    affiche_all();

	//strucutre temporaire en attendant la lecture de fichier
	info inf; //il faudra faire la vrai avec un malloc
	inf.nbjoueurs = 4;
	inf.nbtour = 20;
	inf.nbequipes = 3;

	//lancer le jeu
	int try=jeu(inf);

	wait_escape();
    exit(0);
}
