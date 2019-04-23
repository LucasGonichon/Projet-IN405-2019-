#include <navalmap.h>
#include <math.h>

navire : nmap->map [nmap->shipPosition [shipID] .y][nmap->shipPosition [shipID] .x]

//calcul de portee
// \return 1 si à portée, 0 sinon
int isInRange (coord_t A, coord_t B, int range) {
    if (sqrt (((B.x - A.x)*(B.x - A.x)) + ((B.y - A.y)*(B.y - A.y))) <= range)
        return 1;
    return 0;
}

void attaque (int shipID, coord_t coord, navalmap_t * nmap) {

    if ()
}

void deplacement (int shipID, coord_t vect, navalmap_t * nmap) {
    moveShip (nmap, shipID, vect);
}