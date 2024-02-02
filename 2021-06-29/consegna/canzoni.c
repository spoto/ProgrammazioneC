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
  // DA COMPLETARE
}

/**
 * Stampa gli accordi di una canzone
 */
void print_canzone(struct accordo_t *head) {
  // DA COMPLETARE
}

/**
 * Dealloca gli accordi della canzone
 */
void free_canzone(struct accordo_t *head) {
  // DA COMPLETARE
}
