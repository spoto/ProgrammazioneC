#include <stdio.h>
#include <stdlib.h>  // malloc(), free(), exit()

/**
 * Una lista di elementi, ciascuno contenente una lettera (id) e un valore (value).
 * Si completino tutte le funzioni dichiarate ma non definite nel programma.
 * In particolare, la funzione main() fornita produce il seguente output:
 * Max element A: 5
 *
 * Nota: non e' necessario liberare la memoria allocata.
 */
struct element_t {
    char id;
    int value;
    struct element_t *next;
};

void check_alloc(struct element_t *p);
struct element_t *list_append(struct element_t *head, char id, int value);
void print_max(struct element_t *head);

int main() {
    struct element_t *head = NULL;
    head = list_append(head, 'A', 3);
    head = list_append(head, 'B', 2);
    head = list_append(head, 'B', 1);
    head = list_append(head, 'A', 1);
    head = list_append(head, 'A', 1);
    head = list_append(head, 'C', 2);
    head = list_append(head, 'B', 2);
    print_max(head);
    return 0;
}

/**
 * Controlla se un puntatore è valido, se non è così
 * stampa la stringa "Errore nell'allocazione della memoria.\n" ed esce con exit(-1).
 */
void check_alloc(struct element_t *p) {
    if (p == NULL) {
        printf("Errore nell'allocazione della memoria.\n");
        exit(-1);
    }
}

/**
 * Aggiunge un nodo di tipo element_t alla fine di una lista concatenata di nodi l.
 * Se l e' NULL, crea la lista. Ritorna sempre il puntatore al primo nodo della lista risultante.
 */
struct element_t *list_append(struct element_t *l, char id, int value) {
    struct element_t *new = (struct element_t *)malloc(sizeof(struct element_t));
    check_alloc(new);
    new->id = id;
    new->value = value;
    new->next = NULL;

    if (l == NULL)
        return new;
    else {
        struct element_t *current;
        for (current = l; current->next != NULL; current = current->next)
            ;

        current->next = new;
        return l;
    }
}

// Restituisce la somma dei valori degli id uguali a quello in testa alla lista l
int sum(struct element_t *l) {
    int sum = 0;
    for (int id = l->id; l != NULL; l = l->next)
        if (l->id == id)
            sum += l->value;

    return sum;
}

/**
 * Cerca l'id che ha la somma dei valori piu' alta nella lista, e stampa tale id e tale somma. 
 * Si ipotizza che la lista contenga almeno un elemento.
 * Se ci sono piu' elementi che hanno totalizzato la somma dei valori piu' alta,
 * stampa l'id dell'elemento tra questi che appare per primo nella lista.
 */
void print_max(struct element_t *l) {
    char max_id = l->id;
    int max_sum = sum(l);

    for (l = l->next; l != NULL; l = l->next) {
        int s = sum(l);

        if (s > max_sum) {
            max_id = l->id;
            max_sum = s;
        }
    }

    printf("Max element %c: %d\n", max_id, max_sum);
}
