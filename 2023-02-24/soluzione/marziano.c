#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "marziano.h"

// inizializza l'array indicato, lungo length,
// in modo che diventi un array alfabetico casuale
// (caratteri alfabetici minuscoli o maiuscoli, eventualmente ripetuti)
void init_random(char arr[], int length) {
  srand(time(NULL));

  for (int pos = 0; pos < length; pos++)
  if (rand() % 2 == 0)
    arr[pos] = 'a' + rand() % ('z' - 'a');
	else
	  arr[pos] = 'A' + rand() % ('Z' - 'A');
}

// stampa l'array indicato, su una riga, senza spazi fra i caratteri,
// andando a capo alla fine
void print(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);

  printf("\n");
}

// determina se c e' una vocale
int vocale(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
  	|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// determina se c1 viene prima di c2 nell'ordinamento marziano:
// si assume che entrambi i caratteri siano alfabetici
int in_ordine(char c1, char c2) {
  int c1_vocale = vocale(c1);
  int c2_vocale = vocale(c2);

  if (!c1_vocale && c2_vocale)
    return 1;
  else if (c1_vocale && !c2_vocale)
    return 0;
  else
    return c1 >= c2;
}

// fa una passata sull'array indicato scambiando
// due caratteri consecutivi se non rispettano l'ordinamento marziano
int swap_prima_vocali(char array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (!in_ordine(array[pos], array[pos + 1])) {
      // scambia(array[pos] con array[pos + 1])
      char temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

// riceve un array alfabetico arr e ne sposta i caratteri in modo che
// arr diventi marziano (prima le consonanti, in ordine alfabetico inverso,
// poi le vocali, in ordine alfabetico inverso)
void ordina_marziano(char arr[], int length) {
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


// riceve un array marziano lungo length e restituisce una lista
// che contiene solo le vocali dell'array e senza ripetizioni:
// una vocale viene inserita nella lista solo la prima volta che
// compare, mentre la seconda volta non viene inserita nella lista
struct element_t *vocali_non_ripetute(char arr[], int length) {
  if (length == 0)
    return NULL;
  else {
    struct element_t *result = vocali_non_ripetute(arr + 1, length - 1);
    return (!vocale(arr[0]) || (length > 1 && arr[0] == arr[1])) ? result : crea(arr[0], result);
  }
}
