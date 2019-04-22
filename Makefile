test: all
	./SoD exemple.niveau

all: main.o affichage.o serveur.o
	gcc -o SoD main.o affichage.o serveur.o -I./navalmap/include -L./navalmap -lnm -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

main.o: main.c affichage.h serveur.h
	gcc -Wall -c `sdl-config --cflags` main.c -I./navalmap/include -L./navalmap -lnm

affichage.o: affichage.c affichage.h
	gcc -Wall -c `sdl-config --cflags` affichage.c -I./navalmap/include -L./navalmap -lnm 

serveur.o: serveur.c serveur.h
	gcc -Wall -c -lpthread serveur.c -I./navalmap/include -L./navalmap -lnm 

clean:
	rm -f navalmap.exe *.o
