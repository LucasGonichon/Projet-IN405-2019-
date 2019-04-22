#include "serveur.h"
#include <unistd.h>

void *fjoueur(void *arg)
{
    printf("Nous sommes dans le thread.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}



int jeu(info inf){
	
	int i;
	pthread_t* joueurs=malloc(inf.nbjoueurs * sizeof(pthread_t));
	
	for(i=0;i<inf.nbjoueurs;i++){
		//on lance nbjoueur threads
		if (pthread_create(&joueurs[i], NULL, fjoueur, NULL)) {
			perror("pthread_create");
			return EXIT_FAILURE;
		}
	}
	
	
	for(i=0; i<inf.nbtour;i++){
		//le serveur gère nbtour
		
		
		
	}
	
	for(i=0;i<inf.nbjoueurs;i++){
		//on ferme nbjoueur threads
		if (pthread_join(joueurs[i], NULL)) {
			perror("pthread_join");
			return EXIT_FAILURE;
		}
	}
	
	free(joueurs);
	return 0;
}
