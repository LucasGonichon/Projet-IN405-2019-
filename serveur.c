#include "serveur.h"
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void *fjoueur(void *arg)
{
    printf("Nous sommes dans le thread.\n");

    /* Pour enlever le warning */
    (void) arg;
    pthread_exit(NULL);
}



int equipe(info inf){
	
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

int jeu(info inf){
	int i;
	pid_t pid = 1;
	
	for(i=0;i<inf.nbequipes && pid>0;i++){
		//on lance nbequipes processus
		pid = fork();
		if (pid==-1){
			printf("erreur de fork\n");
			exit(1);
		}
	}
	printf("%d\n",(int)pid);
	
	if(pid==0){
		printf("jesuis fils\n");
		
		exit(0);
	}
	
	if (pid>0){ //si père
		for(i=0;i<inf.nbequipes;i++){
		//on ferme nbequipes processus
		printf("wiat\n");
		if (wait(NULL) == -1) {
				perror("wait :");
				exit(EXIT_FAILURE);
			}

		}
		
	}
}
