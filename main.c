#include <navalmap.h>

#include "affichage.h"
#include "serveur.h"

int main (int argc, char** argv) {

    navalmap_t * map_test;
    coord_t mapsize = {10,10};
    map_test = init_navalmap (MAP_RECT,mapsize,2);
    
    affiche_map (map_test);

    exit(0);
}