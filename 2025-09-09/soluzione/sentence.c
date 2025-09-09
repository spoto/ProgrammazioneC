#include <stdlib.h>
#include <string.h>
#include "sentence.h"

// crea una struttura sentence che contiene le parole fornite,
// nell'ordine in cui sono presenti nell'array;
// tali parole non vanno duplicate: se ne deve solo copiare
// il puntatore dentro la struttura risultante;
// length e' la lunghezza dell'array words
struct sentence *construct_sentence(char *words[], int length) {
  struct sentence *result = NULL;

  for (int pos = length - 1; pos >= 0; pos--) {
    struct sentence *temp = malloc(sizeof(struct sentence));
    temp->word = words[pos];
    temp->next = result;
    result = temp;
  }

  return result;
}

// dealloca una struttura s precedentemente allocata con construct_sentence():
// deve deallocare tutta la lista, non solo il suo primo elemento
void free_sentence(struct sentence *s) {
  while (s) {
    struct sentence *next = s->next;
    free(s);
    s = next;
  }
}

// ritorna la lunghezza di s, cioe' la somma delle lunghezze delle parole di s,
// considerando anche uno spazio tra una parola e l'altra
int length_sentence(struct sentence *s) {
  int result = 0;
  int first = 1; // true

  while (s) {
    result += strlen(s->word);

    if (!first)
      // consideriamo lo spazio prima della parola corrente,
      // ad eccezione della prima parola
      result++;
    else
      first = 0; // false

    s = s->next;
  }

  return result;
}

// concatena le parole di s dentro result, con uno spazio tra una parola
// e l'altra; si assuma che result sia sufficientemente grande da contenere
// il risultato della concatenazione; questa funzione deve essere ricorsiva
void concat_sentence_rec(struct sentence *s, char *result) {
  if (!s)
    *result = '\0';
  else if (!(s->next))
    strcpy(result, s->word);
  else {
    strcpy(result, s->word);
    result += strlen(s->word);
    *(result++) = ' ';
    concat_sentence_rec(s->next, result);
  }
}

// ritorna una nuova stringa che contiene la concatenazione
// delle parole di s, con uno spazio tra una parola e l'altra
char *concat_sentence(struct sentence *s) {
  // allochiamo spazio anche per lo \0 finale
  char *result = malloc(length_sentence(s) + 1);
  concat_sentence_rec(s, result);
  return result;
}

// concatena le parole di s dentro result, con uno spazio tra una parola
// e l'altra, in ordine inverso (prima l'ultima parola, alla fine la prima parola);
// si assuma che result sia sufficientemente grande da contenere
// il risultato della concatenazione; questa funzione deve essere ricorsiva;
// questa funzione ritorna il puntatore alla fine della stringa
// risutante, dove si trova lo \0 finale
char *inverse_concat_sentence_rec(struct sentence *s, char *result) {
  if (!s) {
    *result = '\0';
    return result;
  }
  else if (!(s->next)) {
    strcpy(result, s->word);
    return result + strlen(s->word);
  }
  else {
    result = inverse_concat_sentence_rec(s->next, result);
    *(result++) = ' ';
    strcpy(result, s->word);
    return result + strlen(s->word);
  }
}

// ritorna una nuova stringa che contiene la concatenazione delle parole di s,
// con uno spazio tra una parola e l'altra, in ordine inverso
// (prima l'ultima parola, alla fine la prima parola)
char *inverse_concat_sentence(struct sentence *s) {
  // allochiamo spazio anche per lo \0 finale
  char *result = malloc(length_sentence(s) + 1);
  inverse_concat_sentence_rec(s, result);
  return result;
}
