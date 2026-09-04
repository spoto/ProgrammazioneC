/*
  Una lista di prefissi è una lista di stringhe, che sono tutti i prefissi
  di una stringa di partenza, dal più lungo al più piccolo (cioè al prefisso
  vuoto). Per esempio, i prefissi di "Buongiorno!" sono la lista:

  0: Buongiorno!
  1: Buongiorno
  2: Buongiorn
  3: Buongior
  4: Buongio
  5: Buongi
  6: Buong
  7: Buon
  8: Buo
  9: Bu
  10: B
  11: 

  Si implementi la funzione crea_prefissi, che crea una nuova lista dei
  prefissi di una stringa passata come argomento, e la funzione
  free_list, che dealloca tutta la memoria allocata per la lista
  passata come argomento (cioè sia la lista che le stringhe contenute
  dentro la lista).

  La funzione crea_prefissi deve essere ricorsiva o chiamare una
  funzione ausiliaria ricorsiva e deve allocare dinamicamente
  la stringa contenente ciascun prefisso (deve essere una nuova stringa).

  Si aggiungano gli #include necessari.

  Il resto del programma non deve venire modificato.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list {
  char *prefisso;
  struct list *next;
} List;

List *construct_list(char *prefisso, List *next) {
  List *result = malloc(sizeof(List));
  result->prefisso = prefisso;  
  result->next = next;
  return result;
}

void print_list(List *l) {
  int counter = 0;
  for (List *cursor = l; cursor != NULL; cursor = cursor->next)
    printf("%i: %s\n", counter++, cursor->prefisso);
}

List *crea_prefissi_rec(const char *s, int length) {
  char *prefisso = malloc(length + 1);

  for (int pos = 0; pos < length; pos++)
    prefisso[pos] = s[pos];

  prefisso[length] = '\0';

  if (length == 0)
    return construct_list(prefisso, NULL);
  else
    return construct_list(prefisso, crea_prefissi_rec(s, length - 1));
}

// Crea una nuova lista dei prefissi di s.
// La funzione crea_prefissi deve essere ricorsiva o chiamare una
// funzione ausiliaria ricorsiva e deve allocare dinamicamente
// la stringa contenente ciascun prefisso (deve essere una nuova stringa).
List *crea_prefissi(const char *s) {
  return crea_prefissi_rec(s, strlen(s));
}

// Dealloca tutta la memoria allocata per l (dealloca sia la lista
// che i prefissi al suo interno)
void free_list(List *l) {
  if (l) {
    free_list(l->next);
    free(l->prefisso);
    free(l);
  }
}

int main(void) {
  char s[101];
  scanf("%100s", s);
  List *l = crea_prefissi(s);
  print_list(l);
  free_list(l);
  return 0;
}
