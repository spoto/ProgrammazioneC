#include <stdio.h>

// stampa un triangolo rettangolo di altezza h, con
// l'angolo retto in basso a sinistra, con bordi sinistro e destro
// fatti dal carattere '@' e con l'interno riempito dal carattere '*'
// (si veda la stampa di esempio)
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
void triangle(int h) {
  if (h > 0) {
    triangle(h - 1);

    for (int x = 0; x < h; x++)
      if (x == 0 || x == h - 1 || h <= 2)
	      printf("@");
      else
	      printf("*");

    printf("\n");
  }
}

int main(void) {
  triangle(5);
  triangle(8);
  return 0;
}
