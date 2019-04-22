test: all
	./SoD exemple.niveau

all: main.o affichage.o serveur.o
	gcc -o SoD main.o affichage.o serveur.o -I./navalmap/include -L./navalmap -lnm -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf -lpthread

main.o: main.c affichage.h serveur.h
	gcc -Wall -c `sdl-config --cflags` main.c -I./navalmap/include -L./navalmap -lnm

affichage.o: affichage.c affichage.h
	gcc -Wall -c `sdl-config --cflags` affichage.c -I./navalmap/include -L./navalmap -lnm 

lecture.o: lecture.c
	gcc -Wall -c lecture.c -I./navalmap/include -L./navalmap

serveur.o: serveur.c serveur.h
	gcc -Wall -c serveur.c -I./navalmap/include -L./navalmap -lnm -lpthread

clean:
	rm -f SoD *.o
