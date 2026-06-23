/*
  La struct person descrive una persona, in termini di
  nome, cognome e data di nascita. Si implementino le funzioni
  construct_person, free_person e legal_age e si aggiungano gli
  #include necessari. Il resto del programma non deve venire modificato.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 100
#define MAX_SURNAME 200

struct date {
  int day;
  int month;
  int year;
};

struct person {
  char *name;
  char *surname;
  struct date *birthday;
};

// stampa la data indicata sul video
void print_date(struct date *d) {
  printf("%02i/%02i/%02i", d->day, d->month, d->year);
}

// stampa la persona indicata sul video
void print_person(struct person *p) {
  printf("%s %s (", p->name, p->surname);
  print_date(p->birthday);
  printf(")");
}

/*
Questa funzione deve creare dinamicamente una nuova struct person e
restituire un puntatore ad essa. La persona creata deve avere:

  - il campo name uguale alla stringa name passata come parametro;
  - il campo surname uguale alla stringa surname passata come parametro;
  - il campo birthday contenente day, month e year passati come parametri.

Attenzione: deve essere creata una copia in memoria dinamica
delle stringhe name e surname. Non è sufficiente assegnare direttamente
i puntatori ricevuti come parametri. In altre parole, la nuova struct person
allocata dinamicamente deve contenere una copia indipendente
delle stringhe name e surname.

Questa funzione deve ritornare NULL se name e' piu' lungo di MAX_NAME
oppure se surname e' piu' lungo di MAX_SURNAME.
*/
struct person *construct_person(char *name, char *surname, int day, int month, int year) {
  if (strlen(name) > MAX_NAME || strlen(surname) > MAX_SURNAME)
    return NULL;

  struct person *result = malloc(sizeof(struct person));
  result->name = strcpy(malloc(strlen(name) + 1), name);
  result->surname = strcpy(malloc(strlen(surname) + 1), surname);
  result->birthday = malloc(sizeof(struct date));
  result->birthday->day = day;
  result->birthday->month = month;
  result->birthday->year = year;

  return result;
}

// cancella la memoria allocata per la persona p
void free_person(struct person *p) {
  free(p->birthday);
  free(p->name);
  free(p->surname);
  free(p);
}

// restituisce una nuova struct date contenente il giorno in cui
// la persona p diventa maggiorenne: normalmente 18 anni esatti dopo
// la sua nascita, con l'eccezione di chi e' nato il 29 febbraio,
// che diventa maggiorenne il primo marzo di 18 anni dopo;
// la persona p non deve venire modificata da questa funzione
struct date *legal_age(struct person *p) {
  struct date *result = malloc(sizeof(struct date));
  struct date *birthday = p->birthday;

  if (birthday->day == 29 && birthday->month == 2) {
    // chi e' nato il 29 febbraio diventa maggiorenne
    // il primo marzo di 18 anni dopo
    result->day = 1;
    result->month = 3;
  }
  else {
    result->day = birthday->day;
    result->month = birthday->month;
  }

  result->year = birthday->year + 18;

  return result;
}

int main(void) {
  char name[MAX_NAME + 1];
  char surname[MAX_SURNAME + 1];
  int day, month, year;
  scanf("%100s %200s %i %i %i", name, surname, &day, &month, &year);
  struct person *p = construct_person(name, surname, day, month, year);
  struct date *le = legal_age(p);
  print_person(p);
  printf(" diventa maggiorenne il ");
  print_date(le);
  printf("\n");
  free(le);
  free_person(p);

  return 0;
}
