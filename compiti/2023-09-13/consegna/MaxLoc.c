#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int val;
    struct Lista * next;
};
typedef struct Lista LL;
LL * add(int, LL* );
int isLocMax(LL* , int );

//funzione che aggiunge un elemento
//in testa ad una lista di interi.
LL * add(int num, LL* l) {
    // ... a cura delle/i studentesse/i
}

//funzione che verifica se esiste almeno un
//elemento nella lista h con campo valore uguale
//a n che è un massimo locale.
//La funzione deve restituire 0 in caso di riposta
//negativa ed 1 in caso di risposta positiva.

int isLocMax(LL* h, int n) {
    // ... a cura delle/i studentesse/i
}

//l'esecuzione del main deve provocare le seguenti stampe:
//1 e' locmax di l0
//1 non e' locmax di l1
//3 e' locmax di l2
//3 e' locmax di l3

int main(void) {
    int n;
    
    LL* l0=add(1,NULL);
    LL* l1=add(1,add(1,NULL));
    LL* l2=add(1,add(1,add(3,NULL)));
    LL* l3= add(9,add(1,add(3,add(2,add(6,NULL)))));
    n=1;
    if (isLocMax(l0, n)) {
        printf("%d e' locmax di l0 \n", n);
    } else {
        printf("%d non e' locmax di l0\n", n);
    }
    if (isLocMax(l1, n)) {
        printf("%d e' locmax di l1\n", n);
    } else {
        printf("%d non e' locmax di l1\n", n);
    }
    n = 3;
    if (isLocMax(l2, n)) {
        printf("%d e' locmax di l2\n", n);
    } else {
        printf("%d non e' locmax di l2\n", n);
    }
    if (isLocMax(l3, n)) {
        printf("%d e' locmax di l3\n", n);
    } else {
        printf("%d non e' locmax di l3 \n", n);
    }
    return 0;
}
