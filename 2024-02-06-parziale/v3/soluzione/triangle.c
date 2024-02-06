#include <stdio.h>

// stampa un triangolo rettangolo di altezza h, con
// l'angolo retto in alto a sinistra, con bordi sinistro e destro
// fatti dal carattere '@' e con l'interno riempito dalle
// lettere alfabetiche minuscole decrescenti, fino ad arrivare alla 'a'
// in basso (si veda la stampa di esempio)
// QUESTA FUNZIONE DEVE ESSERE RICORSIVA
void triangle(int h) {
  if (h > 0) {
    for (int x = 0; x < h; x++)
      if (x == 0 || x == h - 1 || h <= 2)
	      printf("@");
      else
	      printf("%c", 'a' + h - 3);

    printf("\n");
    triangle(h - 1);
  }
}

int main(void) {
  triangle(5);
  triangle(8);
  return 0;
}
