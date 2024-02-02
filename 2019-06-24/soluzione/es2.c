#include <stdio.h>


void cambia(int a, int *b, int * c) {
  
  a=15;

  *b=7;

  b=c;
}

int main() {
  int x;
  int y;
  int *z, *k;

  x=55;
  y=12;
  k=&x;
  z=&y;

  printf("Valori: x=%d y=%d k=%d z=%d\n", x, y, *k, *z); 

  cambia(y, k, z);

  printf("Valori: x=%d y=%d k=%d z=%d\n", x, y, *k, *z); // cosa stampa?



  return 0;
}

// Il valore di x e' stato modificato da 55 a 7 perche' una copia del puntatore a x e' stata passata come parametro alla funzione modifica. I valori di y e k passati come parametri alla funzione invece non vengono modificati perche' sono stati passati per valore e non per riferimento come nel caso di x.
