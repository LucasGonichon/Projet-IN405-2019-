#include "affichage.h"
#include "serveur.h"

int main (int argc, char** argv) {

    navalmap_t * map;
    coord_t mapsize = {10,10};
    map = init_navalmap (MAP_RECT,mapsize,2);
    init_graphics(TAILLE*map->size.x,TAILLE*map->size.x);
    affiche_auto_off();
    affiche_map (map);
    affiche_all();

	wait_escape();
    exit(0);
}
