test: all
	./SoD exemple.niveau

all: main.o affichage.o lecture.o
	gcc -o SoD main.o affichage.o lecture.o -I./navalmap/include -L./navalmap -lnm -luvsqgraphics `sdl-config --libs` -lm -lSDL_ttf

main.o: main.c affichage.h
	gcc -Wall -c `sdl-config --cflags` main.c -I./navalmap/include -L./navalmap -lnm

affichage.o: affichage.c affichage.h
	gcc -Wall -c `sdl-config --cflags` affichage.c -I./navalmap/include -L./navalmap -lnm 

lecture.o: lecture.c
	gcc -Wall -c lecture.c

clean:
	rm -f SoD *.o
