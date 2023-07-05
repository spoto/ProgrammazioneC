#include <stdio.h>
#include <stdlib.h>

struct nodo *crea_lista_multipli_3(struct nodo *head,int valore);
float calcola_media(struct nodo *head);
void print_lista(struct nodo *head);
struct nodo *crea_nodo(int value);

struct nodo {
    int value;
    struct nodo *next;
};

/*
 * Program entry point
 */
int main() {
    int n = 150;
    struct nodo* head = (struct nodo *)malloc(sizeof(struct nodo));
    head=crea_lista_multipli_3(head,n);
    print_lista(head);
    printf("\n");
    printf("La media e' %f\n", calcola_media(head));
  
    return 0;
}

/*
*crea un nodo
*/
struct nodo* crea_nodo(int value){
    struct nodo* new =(struct nodo *)malloc(sizeof(struct nodo));
    new->value=value;
    new->next=NULL;
    return new;
}

/*
 * Crea un lista
 *
 */
struct nodo *crea_lista_multipli_3(struct nodo *head, int n) {
    struct nodo * curr;

    int i=3;   
    curr = crea_nodo(i);
    head=curr;
    i=i+3;
    while (i < n) {
        curr->next=crea_nodo(i);
        curr = curr->next;
        i=i+3;
    }
    return head;
}

/**
 * restituisce la media degli elementi
 */
float calcola_media(struct nodo *head) {
    int conta=0;
    float tmp=0;
    while (head != NULL) { 
        tmp+= head->value;  
        head =head->next;
        conta=conta+1;
    }   
    return tmp/conta;
}



/**
 * Stampa gli elementi della lista
 */
void print_lista(struct nodo *head) {
    while (head != NULL) { 
        printf("%d ",head->value);  
        head=head->next;
    }   
}
