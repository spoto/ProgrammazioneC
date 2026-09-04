/* La libreria del linguaggio C mette a disposizione la funzione
   rand(), che restituisce un intero casuale maggiore o uguale a 0
   ogni volta che viene chiamata. Usando tale funzione, si implementi
   la funzione construct_random_list(), che alloca una lista di
   stringhe alfabetiche minuscole casuali di lunghezza casuale.
   La funzione construct_random_list() deve essere ricorsiva.
   Si implementi inoltre la funzione free_list(), che dealloca una tale
   lista (dealloca sia tutta la lista che tutte le stringhe al suo interno).
   Non si modifichi il resto del codice già fornito. */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct list {
  char *s;
  struct list *tail;
} List;

void print_list(List *l) {
  printf("[");

  for (List *cursor = l; cursor; cursor = cursor->tail)
    printf("\"%s\"%s", cursor->s, cursor->tail ? "," : "");

  printf("]\n");
}

/* Alloca una nuova lista lunga esattamente length, in cui ciascun elemento
   è una nuova stringa di caratteri casuali alfabetici minuscoli
   ed è di lunghezza casuale tra 0 e max inclusi. Questa funzione
   deve essere ricorsiva. Si dia per vero che length >= 0 e che max >= 0. */
List *construct_random_list(int length, int max) {
  // COMPLETATE, DEVE ESSERE RICORSIVA
}

/* Dealloca la lista l, dall'inizio alla fine, deallocando anche le
   stringhe al suo interno */
void free_list(List *l) {
  // COMPLETATE
}

int main(void) {
  // fissiamo il seme dei numeri casuali, così il risultato è
  // sempre lo stesso in CodeRunner ed è possibile verificare i test
  srand(42);

  int num;
  do {
    printf("Numero di stringhe da generare (>= 0): ");
    scanf("%i", &num);
  }
  while (num < 0);

  int len;
  do {
    printf("Lunghezza massima delle stringhe da generare (>= 0): ");
    scanf("%i", &len);
  }
  while (len < 0);
  
  // costruisce, stampa e dealloca una lista casuale
  List *l = construct_random_list(num, len);
  printf("Una lista di %i stringhe alfabetiche minuscole casuali di lunghezza casuale tra 0 e %i inclusi:\n", num, len);
  printf("l="); print_list(l);
  free_list(l);  

  printf("\n");

  return 0;
}
