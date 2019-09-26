#include <stdio.h>
#include <string.h>
#define MAX 81
/* ricerca di parole in un file di testo */

int main(void)
{
	FILE *f1;
	char p[MAX], s[MAX];
	int cont=0;
	f1=fopen("data.txt", "r");
	if (f1==NULL) {
		printf("Errore apertura del file!\n");
		return 0;
	}
	printf("\nParola da cercare ? ");
	scanf("%s", p);
	fscanf(f1, "%s", s);
	while (!feof(f1)) {
		if (strcmp(s,p) == 0) {
			cont++;
		}
		fscanf(f1, "%s", s);
	}
	printf("Trovata %s %d volte \n", p, cont);
	fclose(f1);
	return 0;
}
