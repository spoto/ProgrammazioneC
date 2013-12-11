#include <stdio.h>

// dichiarazione della funzione stampa_messaggio
// n e' un parametro formale della funzione
// di tipo intero
void stampa_numero_triangolare(int n) {
  int somma = 0;
  int i;

  for (i = 1; i <= n; i++)
    somma += i;

  printf("Il numero triangolare di ordine %i e' %i\n", n, somma);
}

int main(void) {
  // invocazione o chiamata della funzione stampa_messaggio
  stampa_numero_triangolare(5);
  stampa_numero_triangolare(7);
  stampa_numero_triangolare(2);
  stampa_numero_triangolare(5);
  stampa_numero_triangolare(15);

  return 0;
}
