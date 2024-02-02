#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cifre.h"

// inizializza l'array indicato, lungo length,
// in modo che diventi una stringa lunga length-1,
// i cui caratteri siano caratteri di cifre decimali,
// casuali, tali che nell'array risultante non ci
// siano mai due caratteri consecutivi uguali
void init(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    do {
      arr[pos] = '0' + rand() % 10;
    }
    while (pos > 0 && arr[pos - 1] == arr[pos]);

  arr[length] = '\0';
}

// le stringhe italiane delle dieci cifre decimali
char *digits[] = {
  "zero", "uno", "due", "tre", "quattro",
  "cinque", "sei", "sette", "otto", "nove"
};

// si assuma che s sia una stringa di caratteri di cifre decimali;
// questa funzione crea e restituisce una lista di stringhe, fatta
// dalle stringhe italiane corrispondenti ai caratteri di s; per
// esempio, se i primi due caratteri di s fossero '3' e '5', allora
// la lista risultante deve avere come primi due elementi la stringa
// "tre" e poi la stringa "cinque";
// questa funzione mette nel risultato le stringhe dell'array digits
// definito sopra, direttamente, senza farne copie;
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
struct list *create_list(char *s) {
  if (!*s)
    return NULL;
  else {
    struct list *result = malloc(sizeof(struct list));
    result -> head = digits[*s - '0'];
    result -> tail = create_list(s + 1);
    return result;
  }
}

// dealloca una lista di stringhe che era stata precedentemente
// creata da create_list;
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
void free_list(struct list *l) {
  if (l) {
    free_list(l -> tail);
    free(l);
  }
}

// identica alla funzione create_list, ma fa delle copie delle stringhe
// dell'array digits;
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
struct list *create_list2(char *s) {
  if (!*s)
    return NULL;
  else {
    struct list *result = malloc(sizeof(struct list));
    char* digit = digits[*s - '0'];
    result -> head = malloc(strlen(digit) + 1);
    strcpy(result -> head, digit);
    result -> tail = create_list2(s + 1);
    return result;
  }
}

// identica alla funzione free_list, ma si applica a liste
// precedentemente allocate dalla funzione create_list2;
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
void free_list2(struct list *l) {
  if (l) {
    free_list(l -> tail);
    free(l -> head); // dobbiamo deallocare anche la copia
    free(l);
  }
}

// stampa una lista di stringhe, con uno spazio fra gli elementi,
// andando a capo alla fine
void print_list(struct list *l) {
  while (l) {
    printf("%s ", l -> head);
    l = l -> tail;
  }

  printf("\n");
}

