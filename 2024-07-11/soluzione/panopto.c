#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data {
	int giorno;
    int mese;
    int anno;
};

struct corso {
   char codice_corso[6];
   int CFU;
   struct data data_inizio;
   struct corso *next;
};

struct corso *construct_entry(char codice_corso[], int CFU, struct data d,
  struct corso *next) {
	struct corso * this=malloc(sizeof(struct corso));
	strcpy(this->codice_corso, codice_corso);
	this->CFU=CFU;
	(this->data_inizio).giorno=d.giorno;
	(this->data_inizio).mese=d.mese;
	(this->data_inizio).anno=d.anno;
	this->next=next;
	return this;
}


int list_length(struct corso *l) {
	int conta=0;
 	while(l!=NULL){
 		conta++;
 		l=l->next;}
	return conta;
}

void print_list(struct corso *l) {
	while(l!=NULL){
		printf("anno %d: %s: %d CFU\n",l->data_inizio.anno, l->codice_corso, l->CFU);
 		l=l->next;
 	}
}

void destroy_list(struct corso *l) {	
  if (l == NULL)
    {}
  else {
    destroy_list(l->next);
    //free(l->codice_corso) se da qualche parte usano malloc
    free(l);
  }
}


int valid_study_plan (struct corso *l, int anno){
//che riceve in input una lista e un anno, e verifica se la somma dei CFU dei corsi dell'anno dato e' almeno 60.
	int totCFU = 0;
	while(l!=NULL){
		if (l->data_inizio.anno==anno)
			totCFU+=l->CFU;
		l=l->next;
		}
		printf("totale cfu %d\n",totCFU);
		return totCFU>=60?1:0;
}


struct corso * create_by_sector(struct corso *l, char s){
	struct corso* new_list=NULL;
	struct corso* node;
	struct corso *head=NULL;
	while (l!=NULL){
		if(l->codice_corso[0]==s){	
			 node=construct_entry(l->codice_corso,l->CFU,l->data_inizio,NULL);
		     if (new_list==NULL){
		     	new_list=node;
		     	head=node;}
    	    	else{
    	    		new_list->next=node;
		
			new_list=new_list->next;
    	    } 
    	}//if
    	l=l->next; 
    	}//while
    	return head;
}


struct corso * create_by_sector_ric(struct corso *l, char s){
	if (l==NULL) 
		return NULL;
	if(l->codice_corso[0]==s)
		return	construct_entry(l->codice_corso, l->CFU, l->data_inizio, create_by_sector_ric(l->next, s));
	else
    	return create_by_sector_ric(l->next, s);
}



struct corso * add_from_input (struct corso *l) {
	for(int i = 0; i < 5; i++) {
		 int creditiInput = 0, giorno = 0, mese = 0, anno = 0;
		 char codiceCorso[6];
		 
		 printf("Inserisci il codice del corso: ");
		 scanf("%5s", codiceCorso);
		 
		 do {
			printf("Inserire i crediti di un corso: ");
			scanf("%d", &creditiInput);
			if (creditiInput <= 0 || creditiInput > 12) {
				printf("Errore! Riprova!");
			}
		 } while (creditiInput <= 0 || creditiInput > 12); 
		 
		 do {
			printf("Inserire il giorno di inizio di un corso: ");
			scanf("%d", &giorno);
			if (giorno <= 0 || giorno > 31) {
				printf("Errore! Riprova!\n");
			}
		 } while (giorno <= 0 || giorno > 31); 
		 
		 do {
			printf("\nInserire il mese di inizio di un corso: ");
			scanf("%d", &mese);
			if (mese <= 0 || mese > 12) {
				printf("Errore! Riprova!");
			}
		 } while (mese <= 0 || mese > 12); 
		 
		 do {
			printf("Inserire l'anno di inizio di un corso: ");
			scanf("%d", &anno);
			if (anno <= 1990 || anno > 2025) {
				printf("Errore! Riprova!");
			}
		 } while (anno <= 1990 || anno > 2025); 
		 l=construct_entry( codiceCorso, creditiInput,(struct data) {giorno,mese,anno}, l);
	 }
	 return l;
}

int main(void) {
	 struct corso *l = NULL;
     l = construct_entry( "BI006", 10, (struct data){2,3,2024}, l);
     l=construct_entry( "INF04", 10,(struct data) {2,3,2024}, l);
     l=construct_entry("INF03",8,(struct data){11,11,2023}, l);
     l=construct_entry( "BI005", 12,(struct data) {1,3,2024}, l);
     l=construct_entry( "INF02", 12,(struct data) {12,4,2023}, l);
     l=construct_entry("INF01",8,(struct data){11,6,2023}, l);
     l=construct_entry( "BI004", 12,(struct data) {21,5,2024}, l);
     l=construct_entry( "BI003", 12,(struct data) {21,5,2024}, l);
     l=construct_entry( "BI002", 12,(struct data) {21,5,2024}, l);
     l=construct_entry( "BI001", 12,(struct data) {21,5,2024}, l);
	 
	 l = add_from_input(l);
	 
	 printf("La lista di corsi e' lunga %d\n", list_length(l));
	 printf("I corsi sono:\n");
	 print_list(l);
	 printf("Piano di studio valido: %d\n", valid_study_plan (l, 2023));
	 printf("Piano di studio valido: %d\n", valid_study_plan (l, 2024));
	 struct corso * sector_plan=create_by_sector(l,'B');
	 print_list(sector_plan);
	 sector_plan=create_by_sector_ric(l,'M');
	 	 print_list(sector_plan);
	  destroy_list(sector_plan);
	  destroy_list(l);
  return 0;
}

