#include <navalmap.h>
#include <stdio.h>

void affiche_map (navalmap_t * map) {
    system ("clear");
    for (int j = map->size.y; j > 0; j++) {
        for (int i = 0; i < map->size.x; i++) {
            printf ("-");
        }
        printf ("\n");
    }
}