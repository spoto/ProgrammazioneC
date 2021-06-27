#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct node_t {
    char value;
    struct node_t *next;
};

struct node_t *new_node(char value);
struct node_t *new_list(char *s);
bool is_vowel(char ch);
void double_vowels(struct node_t *n);
void print_list(struct node_t *n);

/**
 * Entry point del programma.
 * Per le lettere considerare solo le minuscole.
 * Non gestire la deallocazione della memoria.
 * Output:
 * hello darkness my old friend
 * heelloo daarkneess my oold friieend
 */
int main() {
    char s[] = "hello darkness my old friend";
    struct node_t *head = new_list(s);

    print_list(head);
    printf("\n");

    double_vowels(head);
    print_list(head);
    printf("\n");
    return 0;
}

/**
 * Crea un nuovo nodo e restituisce il puntatore a esso.
 */
struct node_t *new_node(char value) {
}

/**
 * Crea una nuova lista di nodi con i caratteri della stringa s
 * e restituisce il puntatore al primo nodo.
 */
struct node_t *new_list(char *s) {
}

/**
 * Ritorna true se ch è una vocale italiana (aeiou), false altrimenti.
 * Considerare solo le lettere minuscole.
 */
bool is_vowel(char ch) {
}

/**
 * Modifica la lista raddoppiando i nodi delle vocali
 * Es. h->e->l->l->o diventa h->e->e->l->l->o->0
 */
void double_vowels(struct node_t *head) {
}

/**
 * Stampa i valori dei nodi della lista
 */
void print_list(struct node_t *head) {
}
