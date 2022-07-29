#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vulcaniano.h"

// inizializza l'array indicato, lungo length,
// in modo che diventi un array minuscolo casuale
// (caratteri alfabetici minuscoli, eventualmente ripetuti)
void init_random(char arr[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++)
    arr[pos] = 'a' + rand() % ('z' - 'a');
}

// stampa l'array indicato, su una riga, senza spazi fra i caratteri,
// andando a capo alla fine
void print(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);

  printf("\n");
}

// determina se c e' una vocale minuscola
int vocale(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

// determina se c1 viene prima di c2 nell'ordinamento vulcaniano:
// si assume che entrambi i caratteri siano alfabetici minuscoli
int in_ordine(char c1, char c2) {
  int c1_vocale = vocale(c1);
  int c2_vocale = vocale(c2);

  if (c1_vocale && !c2_vocale)
    return 1;
  else if (!c1_vocale && c2_vocale)
    return 0;
  else
    return c1 <= c2;
}

// fa una passata sull'array indicato scambiando
// due caratteri consecutivi se non rispettano l'ordinamento vulcaniano
int swap_prima_vocali(char array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (!in_ordine(array[pos], array[pos + 1])) {
      // scambia(array[pos] con array[pos + 1])
      int temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

// riceve un array minuscolo arr e ne sposta i caratteri in modo che
// arr diventi vulcaniano (prima le vocali, in ordine alfabetico,
// poi le consonanti, in ordine alfabetico)
void ordina_vulcaniano(char arr[], int length) {
  while (swap_prima_vocali(arr, length));  
}

// crea un nodo di una lista
struct element_t *crea(char value, struct element_t *next) {
  struct element_t *result = malloc(sizeof(struct element_t));
  result -> value = value;
  result -> next = next;
  return result;
}

// stampa una lista di caratteri, senza spazio fra i caratteri,
// andando a capo alla fine
void print_list(struct element_t *l) {
  while (l) {
    printf("%c", l -> value);
    l = l -> next;
  }

  printf("\n");
}

// riceve un array vulcaniano lungo length e restituisce una lista che contiene
// i caratteri dell'array ma senza ripetizioni: un carattere viene inserito
// nella lista solo la prima volta che compare, la seconda volta viene scartato
// e non viene inserito
struct element_t *non_ripetuti(char arr[], int length) {
  if (length == 0)
    return NULL;
  else {
    struct element_t *result = non_ripetuti(arr + 1, length - 1);
    return (length > 1 && arr[0] == arr[1]) ? result : crea(arr[0], result);
  }
}
