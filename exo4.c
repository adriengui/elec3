#include <stdio.h>
#include <stdlib.h>

int estUnEntier(char *s) {
	do{
		if(*s<'0' || *s>'9')
			return 0;
	} while(*++s);

	return 1;
}

int main(int argc, char *argv[]) {

	if(argc==1) {
		printf("Aucun parametre\n");
		exit(EXIT_FAILURE);
	}

	int somme=0,x=0;

	while(*++argv) {
		if(!estUnEntier(*argv)) {
			printf("Erreur parametres\n");
			exit(EXIT_FAILURE);
		}

		x=atoi(*argv);		

		if(!(x&1))
			somme+=x;
	} 

	printf("%d\n",somme);

	return EXIT_SUCCESS;
}		
