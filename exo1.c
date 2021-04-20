#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int jour, mois, annee;
	char *nomDuMois;
} Date;

char *leNomDuMois(const int m) {
	static char *mois[]={"Janvier","Fevrier","Mars","Avril","Mai","Juin","Juillet","Aout","Septembre","Octobre","Novembre","Decembre"};
	char **s=mois-1;

	for(int x=0;x<m;x++)
		s++;

	return *s;
}

int nbJoursDansLeMois(const int m, const int a) {
	static const int n[]={31,0,31,30,31,30,31,31,30,31,30,31};
	if(m==2)
		return ( ( !(a%4) && (a%100) ) || !(a%400) ) ? 29 : 28;
	else
		return n[m-1];
}

Date demain(Date z){
	int j=z.jour+1,m=z.mois,n=z.annee;
	if(z.jour == nbJoursDansLeMois(z.mois,z.annee)) {
		j=1;
		if(z.mois!=12)
			m++;

		else {
			m=1;
			n++;
		}
	}
	Date y={j,m,n};
	y.nomDuMois=leNomDuMois(m);

	return y;
}

int main(int argc, char *argv[]) {

	Date a={31,12,1990};
	a.nomDuMois=leNomDuMois(a.mois);

	Date b=demain(a);

	printf("Date : %d %s %d\n", a.jour, a.nomDuMois, a.annee);
	printf("Lendemain : %d %s %d\n", b.jour, b.nomDuMois, b.annee);

	printf("----------------------------\n");

	Date c={28,2,2021};
	c.nomDuMois=leNomDuMois(c.mois);

	Date d=demain(c);

	printf("Date : %d %s %d\n",c.jour, c.nomDuMois, c.annee);
	printf("Lendemain : %d %s %d\n", d.jour, d.nomDuMois, d.annee);

	return EXIT_SUCCESS;
}
