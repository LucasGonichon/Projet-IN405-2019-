#include "serveur.h"
#include "joueur.h"
#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <uvsqgraphics.h>

int joueur(int nbTours, t_pipe pipe){//fonction de chaque joueur(fork)
	int j;
	message act;
	close(pipe.cote[0]);
	char mess[3];
	for(j=0;j<nbTours;j++){
		
		//decision
		int a=alea_int(2);
		int b,c=0;
		if (a==0){
			act.action=ATK;
			while(a+b<2||a+b>4){
				a=alea_int(5);
				b=alea_int(5);
			}
		}
		else{
			act.action=MOV;
			b=10;
			while(a+b>2||a+b==0){
				a=alea_int(3);
				b=alea_int(3);
			}
		}
		c=alea_int(2);
		if (c==1) a=-a;
		c=alea_int(2);
		if (c==1) b=-b;
		
		act.x=a;
		act.y=b;
		
		//envoie au serv
		mess[0]=act.action+'0';
		mess[1]=act.x+'0';
		mess[2]=act.y+'0';
		write(pipe.cote[1],mess,sizeof(char)*3);
	}
	
}

int jeu(jeu_t * jmap, int nbTours){//focntion du serveur
	int i,j;
	pid_t pid = 1;
	t_pipe * pip = malloc(sizeof(t_pipe) * jmap->nmap->nbShips);
	
	for(i=0;i<jmap->nmap->nbShips && pid>0;i++){
		//on créé les pipe
		pipe(pip[i].cote);
		
		//on lance nbequipes processus
		pid = fork();
		if (pid==-1){
			printf("erreur de fork\n");
			exit(1);
		}
	}
	printf("%d\n",(int)pid);
	
	if(pid==0){
		int T=joueur(nbTours, pip[i-1]);
		
		exit(0);
	}
	
	if (pid>0){ //si père
		
		for(i=0; i<jmap->nmap->nbShips;i++)		//on ferme les entree ecriture
			close(pip[i].cote[1]);
		
		
		//gère les tours
		message * actions= malloc(sizeof(message)*jmap->nmap->nbShips);
		char mess[3];
		for(i=0;i<nbTours;i++){
			
			for(j=0;j<jmap->nmap->nbShips;j++){
				//recoit les infos des processus
				read(pip[j].cote[0],mess,sizeof(char)*3);
				actions[j].action=mess[0]-48;
				actions[j].x=mess[1]-48;
				actions[j].y=mess[2]-48;
			}

			for(j=0;j<jmap->nmap->nbShips;j++){
				doMessage (jmap, j, actions[j]);
			}
		}
		
		for(i=0;i<jmap->nmap->nbShips;i++){
		//on ferme nbequipes processus
		printf("wait\n");
		if (wait(NULL) == -1) {
				perror("wait :");
				exit(EXIT_FAILURE);
			}

		}
		free(actions);
	}
	free(pip);
}
