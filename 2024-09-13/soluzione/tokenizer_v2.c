//soluzione che combina gli approcci degli studenti D'errico Giordanobruno e Solinas Nicola
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 50
#define MAX_STRING_LENGTH 300

struct Nodo{
  char nome[MAX_LENGTH];
  struct Nodo* next;
};

struct Nodo * mystrtok(char *s) {
	struct Nodo *head = NULL;
	struct Nodo *current = NULL;
	char *token = s;
	int i = 0;
	struct Nodo* new_node = (struct Nodo*) malloc(sizeof(struct Nodo));
	while (*token) {
		if(*token == ';' || *token=='\0'){
			new_node->nome[i] = '\0';
			token++;
			new_node->next = head;
			head = new_node;
			i=0;
			new_node = (struct Nodo*) malloc(sizeof(struct Nodo));
		}
		else{
		 	if(i<MAX_LENGTH - 1) {
				new_node->nome[i++] = *token++;
			}
			else{
				token++;//ignoro i caratteri che superano MAX_LENGTH
			}
		}//else
	}//while
	return head;
}

void print_list(struct Nodo *l) {
 	while (l != NULL) {
 		printf("%s\n", l->nome);
		l = l->next;
 	}
}

int caratteri_validi(char * elenco){
	while(*elenco) {
		if (!((*elenco >= 'A' && *elenco <= 'Z') || (*elenco >= 'a' && *elenco <= 'z') || *elenco == ';')) {
			return 0;
		}	
	elenco++;
	}
	return 1;	
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







