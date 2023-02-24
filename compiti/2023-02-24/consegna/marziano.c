// aggiungete gli #include necessari
#include "marziano.h"

// inizializza l'array indicato, lungo length,
// in modo che diventi un array alfabetico casuale
// (caratteri alfabetici minuscoli o maiuscoli, eventualmente ripetuti)
void init_random(char arr[], int length) {
  // completare
}

// stampa l'array indicato, su una riga, senza spazi fra i caratteri,
// andando a capo alla fine
void print(char arr[], int length) {
  // completare
}

// riceve un array alfabetico arr e ne sposta i caratteri in modo che
// arr diventi marziano (prima le consonanti, in ordine alfabetico inverso,
// poi le vocali, in ordine alfabetico inverso)
void ordina_marziano(char arr[], int length) {
  // completare
}

// stampa una lista di caratteri, senza spazio fra i caratteri,
// andando a capo alla fine
void print_list(struct element_t *l) {
  // completare
}


// riceve un array marziano lungo length e restituisce una lista
// che contiene solo le vocali dell'array e senza ripetizioni:
// una vocale viene inserita nella lista solo la prima volta che
// compare, mentre la seconda volta non viene inserita nella lista
struct element_t *vocali_non_ripetute(char arr[], int length) {
  // completare
}
