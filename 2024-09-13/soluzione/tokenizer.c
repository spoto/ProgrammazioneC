#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_LENGTH 50
#define MAX_STRING_LENGTH 300
#define SEPARATOR ';'

struct Nodo{
  char  s[MAX_LENGTH]; 
  struct Nodo* next;
};

struct Nodo *construct_entry( struct Nodo *next, char*s){
  struct Nodo * this=malloc(sizeof(struct Nodo));
  strcpy(this->s, s);
  this->next=next;
  return this;
}

struct Nodo * mystrtok(char *s){
  char *tmp, *inizio_tmp;
  struct Nodo * head=NULL;

  while(*s!='\0'){
    tmp=malloc(MAX_LENGTH);
    inizio_tmp=tmp;
    
    int length = 0;

    // Read characters until the delimiter (';') or the end of string
    while (*s != ';' && *s != '\0') {
      if (length < MAX_LENGTH - 1) {
	*tmp = *s;
	tmp++;
      }
      s++;
      length++; 
    } //while
		
    *tmp='\0';
    head=construct_entry(head,inizio_tmp);
    s++;
  }
  return head;
}

void print_list(struct Nodo *l) {
  while(l!=NULL){
    printf("%s\n" ,l->s);
    l=l->next;
  }
}

int caratteri_validi(char * elenco){
  for (int i=0; i< strlen(elenco);i++){
    if (elenco[i]!=SEPARATOR && (!(isalpha(elenco[i]))) ){
      printf("Caratteri non validi\n");
      return 0;
    }
  }//for
  return 1;
}
	
int main(void){
  char elenco_nomi[MAX_STRING_LENGTH];//ESEMPIO "Maria;Jessica;Kaur;Michela;Marco;Angelica;"
	
  int len = -1;
	
  do{
    printf("Inserisci un elenco di nomi, separati dal punto e virgola (;). La lunghezza deve essere inferiore a %d caratteri: ", MAX_STRING_LENGTH);	
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







