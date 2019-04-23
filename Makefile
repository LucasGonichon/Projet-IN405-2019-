test: all
	./SoD exemple.niveau

all: main.o affichage.o serveur.o lecture.o
	gcc -o SoD main.o affichage.o serveur.o lecture.o -I./navalmap/include -L./navalmap -lnm -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf -lpthread

main.o: main.c affichage.h serveur.h lecture.h mestypes.h
	gcc -Wall -c `sdl-config --cflags` main.c -I./navalmap/include -L./navalmap -lnm

affichage.o: affichage.c affichage.h
	gcc -Wall -c `sdl-config --cflags` affichage.c -I./navalmap/include -L./navalmap -lnm 

lecture.o: lecture.c mestypes.h
	gcc -Wall -c lecture.c -I./navalmap/include -L./navalmap

serveur.o: serveur.c serveur.h mestypes.h
	gcc -Wall -c `sdl-config --cflags` serveur.c -I./navalmap/include -L./navalmap -lnm -lpthread

clean:
	rm -f SoD *.o
