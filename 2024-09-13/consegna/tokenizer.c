#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 50
#define MAX_STRING_LENGTH 300

struct Nodo{
    //definizione di struttura da completare 
};

struct Nodo * mystrtok(char *s){
//da completare
}

void print_list(struct Nodo *l) {
//da completare
}

int caratteri_validi(char * elenco){	
//da completare
}

int main(void){
	char elenco_nomi[MAX_STRING_LENGTH];//ESEMPIO "Maria;Jessica;Kaur;Michela;Marco;Angelica;"
	int len = -1;
	
	do{
		printf("Inserisci un elenco di nomi, separati dal punto e virgola (;). La lunghezza complessiva deve essere inferiore a %d caratteri: ", MAX_STRING_LENGTH);	
		scanf("%s",elenco_nomi);

		len = strlen(elenco_nomi);
		
		if(!caratteri_validi(elenco_nomi) || len >= MAX_STRING_LENGTH) {
			printf("Errore nell'input, riprovare\n");
		}
	}	while(!caratteri_validi(elenco_nomi) || len >= MAX_STRING_LENGTH);
	
	struct Nodo* L=mystrtok(elenco_nomi);
	print_list(L);	
	return 0;
}	







