#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NB_MAX 200

enum opera{EFFECTIF, MIN, MAX, MOYENNE, ECART_TYPE};

void recup(int nb[]){
	int i=1,n=0;
	while(scanf("%d",&n) != EOF){
		if(i==NB_MAX+1)
			break;
		if(n>0 && n%2==0){
			nb[i]=n;
			nb[0]=i;
			i++;
		}
	}
}

void calc(int nb[], double stat[]){
	stat[EFFECTIF]=nb[0];
	stat[MIN]=stat[MAX]=nb[1];
	stat[MOYENNE]=stat[ECART_TYPE]=0;
	for(int x=1;x<=stat[EFFECTIF];x++){
		if(nb[x]<stat[MIN])
			stat[MIN]=nb[x];
		if(nb[x]>stat[MAX])
			stat[MAX]=nb[x];
		stat[MOYENNE]+=nb[x];
	}
	stat[MOYENNE]/=stat[EFFECTIF];
	for(int x=1;x<=stat[EFFECTIF];x++)
		stat[ECART_TYPE]+=pow(nb[x]-stat[MOYENNE],2);
	stat[ECART_TYPE]=sqrt(stat[ECART_TYPE]/stat[EFFECTIF]);
}

void affiche(double stat[]){
	printf("Effectif = %g\nMin = %g\nMax = %g\nMoyenne = %g\nEcart-type = %g\n",stat[EFFECTIF],stat[MIN],stat[MAX],stat[MOYENNE],stat[ECART_TYPE]);
}

int main(){
	int nb[NB_MAX+1];
	double stat[5];
	recup(nb);
	calc(nb,stat);
	affiche(stat);

	return EXIT_SUCCESS;
}
