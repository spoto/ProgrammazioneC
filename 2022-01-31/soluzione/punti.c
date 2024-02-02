/*
 * Il programma va compilato con -lm per utilizzare la funzione sqrt() della libreria math.h:
 * gcc punti.c -lm  // Attenzione -lm va dopo punti.c
 */
#include <math.h>    // sqrt()
#include <stdio.h>   // printf()
#include <stdlib.h>  // malloc()

struct punto_t {
    int x;
    int y;
    struct punto_t *next;
};

struct polilinea_t {
    struct punto_t *head;
};

struct punto_t *new_punto(int x, int y);
struct polilinea_t *new_polilinea();
void add_punto(struct polilinea_t *polilinea, int x, int y);
double distance(struct punto_t *p1, struct punto_t *p2);
double length(struct polilinea_t *polilinea);

/*
 * Program entry punto
 */
int main() {
    struct polilinea_t *polilinea1;
    struct polilinea_t *polilinea2;

    polilinea1 = new_polilinea();
    polilinea2 = new_polilinea();

    add_punto(polilinea1, 0, 0);
    add_punto(polilinea1, 1, 0);
    add_punto(polilinea1, 1, 1);

    printf("Lunghezza polilinea 1: %.2lf\n", length(polilinea1));
    printf("Lunghezza polilinea 2: %.2lf\n", length(polilinea2));
    return 0;
}

/*
 * Crea un nuovo punto con le coordinate specificate
 */
struct punto_t *new_punto(int x, int y) {
    struct punto_t *punto = (struct punto_t *)malloc(sizeof(struct punto_t));
    punto->x = x;
    punto->y = y;
    punto->next = NULL;
    return punto;
}

/*
 * Crea una nuova polilinea
 */
struct polilinea_t *new_polilinea() {
    struct polilinea_t *polilinea = (struct polilinea_t *)malloc(sizeof(struct polilinea_t));
    polilinea->head = NULL;
    return polilinea;
}

/*
 * Aggiunge un punto in coda alla polilinea
 */
void add_punto(struct polilinea_t *polilinea, int x, int y) {
    struct punto_t *punto = new_punto(x, y);

    if (polilinea->head == NULL) {
        polilinea->head = punto;
    } else {
        struct punto_t *current = polilinea->head;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = punto;
    }
}

/*
 * Ritorna la distanza tra due punti
 */
double distance(struct punto_t *p1, struct punto_t *p2) {
    double dx = p1->x - p2->x;
    double dy = p1->y - p2->y;
    return sqrt(dx * dx + dy * dy);
}

/*
 * Ritorna la lunghezza polilinea
 */
double length(struct polilinea_t *polilinea) {
    double _length = 0;

    if (polilinea->head != NULL) {
        struct punto_t *current = polilinea->head;

        while (current->next != NULL) {
            _length += distance(current, current->next);
            current = current->next;
        }
    }

    return _length;
}
