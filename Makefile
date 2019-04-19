all: main.o affichage.o
	gcc -o SoD main.o affichage.o -I./navalmap/include -L./navalmap -lnm

main.o: main.c
	gcc -Wall -c main.c

affichage.o: affichage.c
	gcc -Wall -c affichage.c

clean:
	rm -f navalmap.exe *.o