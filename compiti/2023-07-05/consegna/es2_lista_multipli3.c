#include <stdio.h>
#include <stdlib.h>

struct nodo *crea_lista_multipli_3(struct nodo *head,int valore);
float calcola_media(struct nodo *head);
struct nodo {
    int value;
    struct nodo *next;
};

/**
 * Program entry point
 */
int main() {
    int n = 150;
    struct nodo* head = (struct nodo *)malloc(sizeof(struct nodo));
    head=crea_lista_multipli_3(head,n);
    printf("La media e' %f", calcola_media(head));
   
    return 0;
}


/**
 * Crea un lista con i multipli di 3 positivi e inferiori a n
 */
struct nodo *crea_lista_multipli_3(struct nodo *head, int n) {
   //da completare
}

/**
 * Restituisce la media degli elementi di una lista
 */
float calcola_media(struct nodo *head) {
    //da completare
}

