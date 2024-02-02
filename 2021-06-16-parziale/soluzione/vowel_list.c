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
    struct node_t *new = (struct node_t *)malloc(sizeof(struct node_t));
    new->value = value;
    new->next = NULL;
    return new;
}

/**
 * Crea una nuova lista di nodi con i caratteri della stringa s
 * e restituisce il puntatore al primo nodo.
 */
struct node_t *new_list(char *s) {
    struct node_t *head = NULL;
    struct node_t *prev = NULL;

    while (*s) {
        struct node_t *new = new_node(*s);

        if (head == NULL) {
            head = new;
        } else {
            prev->next = new;
        }
        prev = new;
        s++;
    }
    return head;
}

/**
 * Ritorna true se ch è una vocale italiana (aeiou), false altrimenti.
 * Considerare solo le lettere minuscole.
 */
bool is_vowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

/**
 * Modifica la lista raddoppiando i nodi delle vocali
 * Es. h->e->l->l->o diventa h->e->e->l->l->o->0
 */
void double_vowels(struct node_t *head) {
    struct node_t *current = head;

    while (current) {
        if (is_vowel(current->value)) {
            struct node_t *new = new_node(current->value);
            new->next = current->next;
            current->next = new;
            current = new->next;
        } else {
            current = current->next;
        }
    }
}

/**
 * Stampa i valori dei nodi della lista
 */
void print_list(struct node_t *head) {
    struct node_t *current = head;

    while (current) {
        printf("%c", current->value);
        current = current->next;
    }
}
