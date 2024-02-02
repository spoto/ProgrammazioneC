#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct accordo_t *add_accordo(struct accordo_t *head, char nota, bool minore);
void print_canzone(struct accordo_t *head);
void free_canzone(struct accordo_t *head);

struct accordo_t {
    char nota;
    bool minore;
    struct accordo_t *next;
};

/*
 * Program entry point
 * Output atteso:
 * Am G D Am Em
 */
int main() {
    struct accordo_t *song = NULL;
    song = add_accordo(song, 'A', true);
    add_accordo(song, 'G', false);
    add_accordo(song, 'D', false);
    add_accordo(song, 'A', true);
    add_accordo(song, 'E', true);
    print_canzone(song);
    printf("\n");
    free_canzone(song);
    return 0;
}

/*
 * Crea un accordo e lo aggiunge in fondo a una canzone,
 * restituendo il puntatore al suo primo accordo.
 */
struct accordo_t *add_accordo(struct accordo_t *head, char nota, bool minore) {
    struct accordo_t *new = (struct accordo_t *)malloc(sizeof(struct accordo_t));
    new->nota = nota;
    new->minore = minore;
    struct accordo_t *accordo = head;

    if (accordo == NULL) {
        // Empty list
        head = new;
    } else {
        while (accordo->next != NULL) {
            accordo = accordo->next;
        }
        accordo->next = new;
    }

    return head;
}

/**
 * Stampa gli accordi di una canzone
 */
void print_canzone(struct accordo_t *head) {
    if (head != NULL) {
        printf("%c", head->nota);
        if (head->minore) {
            printf("m");
        }
        printf(" ");

        print_canzone(head->next);
    }
}

/**
 * Dealloca gli accordi della canzone
 */
void free_canzone(struct accordo_t *head) {
    if (head != NULL) {
        free_canzone(head->next);
        free(head);
    }
}
