/*
  Completare il seguente programma che legge da un file di testo,
  il cui nome viene inserito da tastiera, una sequenza di numeri interi
  strettamente positivi. Il programma, tramite la funzione
  
  int conta_coppie(char *nomefile)

  deve contare e stampare a video il numero di coppie adiacenti valide
  nel file. La funzione restituisce -1 se il file di nome nomefile non esiste.

  Data una coppia adiacente di numeri n e m, si dice valida se la cifra
  meno significativa (cifra delle unità) di n è uguale alla cifra
  più significativa di m.

  Ad esempio, dato il file con i seguenti numeri:

  5 56 61 23 45 5

  nel file sono presenti 3 coppie adiacenti valide:

  (5, 56)  (56, 61)  (45, 5)

  Si noti che le coppie considerate possono sovrapporsi: ad esempio, (5, 56)
  e (56, 61) sono entrambe coppie valide.

  Il programma deve infine stampare OK se il numero di coppie valide
  è composto da cifre tutte uguali, e KO altrimenti.

  Nell'esempio precedente il numero di coppie valide è 3; pertanto viene
  stampato OK, poiché un numero costituito da una sola cifra soddisfa
  la proprietà.

  Tale controllo deve essere effettuato mediante la funzione ricorsiva

  int controllocifre(int n);

  che restituisce 1 se tutte le cifre di n sono uguali e 0 altrimenti.
  Un numero costituito da una sola cifra, incluso 0, soddisfa sempre
  la proprietà. Ad esempio, controllocifre(222) restituisce 1,
  controllocifre(0) restituisce 1, mentre controllocifre(13) restituisce 0.
*/

#include <stdio.h>

int controllocifre(int n);
int conta_coppie(char *nome);

int main() {
  char nomefile[100];
  int num_coppie;

  scanf("%s", nomefile);

  num_coppie = conta_coppie(nomefile);

  if (num_coppie == -1) {
    printf("Errore nell'apertura del file.\n");
  } else {
    printf("%d\n", num_coppie);

    if (controllocifre(num_coppie))
      printf("OK\n");
    else
      printf("KO\n");
  }

  return 0;
}


/* Conta le coppie adiacenti valide */
int conta_coppie(char *nome) {
  FILE *fp;
  int n, m;
  int count = 0;
  int prima_cifra;

  fp = fopen(nome, "r");

  if (fp == NULL)
    return -1;

  /* Legge il primo numero */
  if (fscanf(fp, "%d", &n) != 1) {
    fclose(fp);
    return 0;
  }

  /* Legge i numeri successivi */
  while (fscanf(fp, "%d", &m) == 1) {

    /* Trova la cifra più significativa di m */
    prima_cifra = m;

    while (prima_cifra >= 10)
      prima_cifra = prima_cifra / 10;

    /*
     * n % 10 è la cifra meno significativa di n.
     * prima_cifra è la cifra più significativa di m.
     */
    if (n % 10 == prima_cifra)
      count++;

    /* m diventa il primo elemento della prossima coppia */
    n = m;
  }

  fclose(fp);

  return count;
}

/* 
 * Restituisce 1 se tutte le cifre di n sono uguali,
 * 0 altrimenti.
 */
int controllocifre(int n) {

  /* 0 e tutti i numeri di una cifra soddisfano la proprietà */
  if (n < 10)
    return 1;

  /* Confronta le ultime due cifre */
  if (n % 10 != (n / 10) % 10)
    return 0;

  return controllocifre(n / 10);
}
