/*
  Si consideri il tipo List, che implementa una lista di date del calendario.

  Si implementino le due funzioni:
  - construct_list, che alloca e restituisce una nuova lista che inizia
    con la data day/month/year passata come tre parametri interi e
    continua con il next passato come parametro. Non si richiede di controllare
    la validità della data day/month/year;
  - list_from_array, che alloca e restituisce una nuova lista a partire
    da un array passato come parametro. Per esempio, se l'array fosse
    [31,3,2026,31,7,2027,13,1,1973] allora la funzione deve restituire la
    lista di tre date 31/3/2026 -> 31/7/2027 -> 13/1/1973. Questa funzione deve
    essere ricorsiva.

  Non si modifichi il resto del codice. Si aggiungano gli #include necessari.
*/

#include <stdio.h>
#include <stdlib.h>

struct date {
  int day;
  int month;
  int year;
};

typedef struct list {
  struct date *value;
  struct list *next;
} List;

// stampa la lista l sul video
void print_list(List *l) {
  while (l) {
    printf("%d/%d/%d ", l->value->day, l->value->month, l->value->year);
    l = l->next;
  }
}

/*
  Alloca e restituisce una lista che inizia con la data day/month/year e
  continua con next. Non si controlli la validità della data day/month/year.
*/
List *construct_list(int day, int month, int year, List *next) {
  List *result = malloc(sizeof(List));
  result->value = malloc(sizeof(struct date));
  result->value->day = day;
  result->value->month = month;
  result->value->year = year;
  result->next = next;
  return result;
}

/*
   Alloca e restituisce una lista fatta dalle date contenute nell'array arr.
   Per esempio, se l'array fosse [31,3,2026,31,7,2027,13,1,1973], allora
   questa funzione dovrebbe restituire la lista di tre date
   31/3/2026 -> 31/7/2027 -> 13/1/1973.
   Il parametro length è la lunghezza dell'array. Nell'esempio precedente,
   length sarebbe 9. Si noti che length è sempre un multiplo di tre (non
   va controllato, lo si dia per vero). Non si controlli la validità delle
   date. Questa funzione deve essere ricorsiva.
*/
List *list_from_array(int arr[], int length) {
  if (length == 0)
    return NULL;
  else
    return construct_list
      (arr[0], arr[1], arr[2], list_from_array(arr + 3, length - 3));
}

/*
  Chiede all'utente di inserire una sequenza di interi, che interpreta
  come date, che quindi costruisce chiamando list_from_array. Alla fine
  stampa l'array risultante.
 */
int main(void) {
  int length;
  printf("Quante date vuoi inserire? ");
  scanf("%i", &length);
  int *arr = malloc(length * 3 * sizeof(int));
  printf("Inserisci le date: ");
  for (int pos = 0; pos < length; pos++)
    scanf("%i %i %i", &arr[pos * 3], &arr[pos * 3 + 1], &arr[pos * 3 + 2]);

  List *l = list_from_array(arr, length * 3);
  printf("La lista contenente le date è: ");
  print_list(l);
  printf("\n");
  free(arr);
  return 0;
}
