#include <stdio.h>
#include <stdlib.h>

//definizione del tipo di dato per gli elementi di una lista
typedef struct elem {
// da completare 
} Elem;

Elem* crealista(int a[], int size);
void printList(Elem* head);

int main(void) {
	int arr[] = {2,4,4,4,4,6,6,8,8,8,10,10,10};
	int size = sizeof(arr) / sizeof(int);
	Elem* result = crealista(arr, size);
	printf("Lista senza duplicati:\n ");
	printList(result);
	return 0;
}
//funzione che dato un array e la sua lunghezza restituisce 
//il puntatore al primo elemento della lista
Elem* crealista(int a[], int size) {
	// da completare  
}

//funzione che dato il puntatore di testa ad una lista stampa 
//tutti gli elementi della lista
void printList(Elem* head) {
	// da completare  
}

