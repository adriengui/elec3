#include <stdio.h>
#include <stdlib.h>

char *Strchr(char *s, char c) {
	char *r=NULL;
	do{
		if(*s==c)
			r=s;
	} while(*++s);

	return r;
}

int main(int argc, char *argv[]) {

	char *a="Les mauvais en C", *b;

	if( (b=Strchr(a,'a')) != NULL )
		printf("%s\n",b);

	if( (b=Strchr(a,'d')) != NULL )
		printf("%s\n",b);

	return EXIT_SUCCESS;
}		
