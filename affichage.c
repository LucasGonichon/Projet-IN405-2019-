#include "affichage.h"


void affiche_map (navalmap_t * map) {
    POINT p1,p2;
    p1.x=0;
    p2.x=TAILLE * map->size.x;
    for (int j = TAILLE*map->size.y; j > 0; j-=TAILLE) {
		p1.y=p2.y=j;
		draw_line(p1,p2,blanc);
	}
   p1.y=0;
   p2.y=TAILLE * map->size.y;
    for (int i = 0; i < TAILLE*map->size.x; i+=TAILLE) {
		p1.x=p2.x=i;
		draw_line(p1,p2,blanc);
    }
    affiche_all();
}
