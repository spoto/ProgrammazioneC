/*
  Si implementino le funzioni only_primes (che deve essere ricorsiva)
  e read_list. Si aggiungano gli #include necessari. Il resto del
  programma non deve venire modificato.

  La funzione read_list legge una lista di interi non negativi da un file,
  fermandosi quando si incontra qualcosa che non è un numero intero
  e ignorando i numeri negativi. La funzione only_primes restituisce una
  lista contenente tutti e soli i valori della lista parametro che
  sono numeri primi.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct list {
  int value;
  struct list *tail;
} List;

void print_list(List *l) {
  for (List *cursor = l; cursor != NULL; cursor = cursor->tail)
    printf("%i ", cursor->value);

  printf("\n");
}

List *construct_list(int value, List *tail) {
  List *result = malloc(sizeof(List));
  result->value = value;
  result->tail = tail;
  return result;
}

int is_prime(int n) {
  if (n <= 1)
    return 0;

  for (int d = 2; d * d <= n; d++)
    if (n % d == 0)
      return 0;

  return 1;
}

// restituisce una lista contenente tutti e soli i valori
// di l che sono numeri primi; non deve modificare l;
// questa funzione deve essere ricorsiva
List *only_primes(List *l) {
  if (!l)
    return NULL;
  else if (is_prime(l->value))
    return construct_list(l->value, only_primes(l->tail));
  else
    return only_primes(l->tail);
}

// legge i numeri non negativi dal file indicato,
// fermandosi se il file termina o se viene incontrato qualcosa che non
// e' un numero; i numeri negativi nel file vengono semplicemente ignorati;
// va benissimo farlo in modo iterativo oppure ricorsivo: si lascia la scelta
// allo studente
List *read_list(FILE *f) {
  int value;
  if (1 == fscanf(f, "%i", &value))
    if (value >= 0)
      return construct_list(value, read_list(f));
    else // scartato perché negativo
      return read_list(f);
  else
    return NULL;
}

int main(void) {
  char filename[101];
  scanf("%100s", filename);
  FILE *f = fopen(filename, "r");
  if (f == NULL) {
    printf("Non riesco ad aprire %s\n", filename);
    return -1;
  }

  List *l = read_list(f);
  fclose(f);

  List *op = only_primes(l);
  print_list(l); // stampa la lista originale
  print_list(op); // stampa la lista dei soli primi

  return 0;
}
