#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// metodo per creare un nuovo nodo con allocazione dinamica
Player *newPlayer(int id, const char nickname[], float *best_scores) {
    // crea un nuovo nodo e lo inizializza con allocazione dinamica
    Player *lnode = (Player *)malloc(sizeof(Player));

    lnode->id = id;

    strncpy(lnode->nickname, nickname, CHAR_MAX);
    
    for (int i = 0; i < SCORE_MAX; i++) {
        lnode->best_scores[i] = best_scores[i];
    }
    //TODO: alternativa con aritmetica dei puntatori
    // for(int i = 0; i < SCORE_MAX; i++) {
    //     *(lnode->best_scores + i) = *(best_scores + i);
    // } 

    lnode->next = NULL;

    return lnode;
}

int listLen(Player *head) {
    int len = 0;
    Player *curr = head;
    while (curr != NULL) {
        len++;
        curr = curr->next;
    }
    return len;
}

// inserisce un nodo in coda alla lista
Player* insertPlayer(Player* head, Player* n){

    //Gestisce il caso in cui la lista è vuota, in caso affermativo il nuovo nodo sarà anche la testa
	if (head==NULL){
		n->next=NULL;
		return n;
	}
	
    //Ricerca della coda corrente
	Player * curr=head;
	while(curr->next != NULL){
		curr=curr->next;
	}
	
    //collegamento della coda corrente con il nuovo nodo (la nuova coda)
	curr->next=n;
	n->next=NULL;
	
	return head;

}

//inserisce il nodo mantenendo l’ordine decrescente dei valori
Player* insertInOrder(Player *head, Player *n){

    //Verifico se il nuovo nodo deve essere posto in testa alla lista
    if (head==NULL || getMean(n->best_scores) > getMean(head->best_scores)){
        n->next=head;
        return n;
    }

    Player *prec=head;
    Player *curr=head->next;

    //Scorro i nodi della lista finche questa non termina oppure finchè non trovo un nuovo con valore maggiore di quello del nuovo nodo
    while (curr != NULL && getMean(curr->best_scores) > getMean(n->best_scores)) {
        prec=curr;
        curr=curr->next;
    }

    //aggiorno i collegamenti per inserire il nuovo nodo nella posizione corretta
    n->next=curr;
    prec->next=n;

    return head;

}


float getMean(float best_scores[]) {
    float somma = 0;
    for (int i = 0; i < SCORE_MAX; i++) {
        somma += best_scores[i];
    }
    return somma / SCORE_MAX;
}


// Crea una lista di giocatori con media dei punteggi superiore a mediaTop;
// questa funzione deve essere ricorsiva
Player* createTopPlayersList(Player *head, float mediaTop) {
  if (head == NULL)
    return NULL;
  else {
    Player *topPlayers = createTopPlayersList(head->next, mediaTop);

    if (getMean(head->best_scores) >= mediaTop)
      topPlayers = insertInOrder(topPlayers, newPlayer(head->id, head->nickname, head->best_scores));

    return topPlayers;
  }
}


// Stampa il contenuto della lista
void printList(Player *head) {
    Player *curr = head;
    while (curr != NULL) {
        printf("ID: %d, Nickname: %s, Best Scores:", curr->id, curr->nickname);
        for (int i = 0; i < SCORE_MAX; i++) {
            printf(" %.2f", curr->best_scores[i]);
        }
        printf(", Media: %.2f", getMean(curr->best_scores));

        curr = curr->next;
        printf("\n");
    }
}

// Dealloca l'intera lista
void destroyList(Player *head) {
    Player *curr = head;
    while (curr != NULL) {
        Player *temp = curr;
        curr = curr->next;
        free(temp);
    }
}
