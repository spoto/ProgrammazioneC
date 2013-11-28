#include <stdio.h>

int main(void) {
  // dichiara e crea l'array dei voti
  int voti[20];
  int somma;

  // legge da tastiera i 20 voti
  int pos;

  for (pos = 0; pos <= 19; pos++) {
    printf("voto %i: ", pos + 1);
    scanf("%i", &voti[pos]);
  }

  // stampa i 20 voti
  printf("Ecco i voti che hai immesso:\n");

  for (pos = 0; pos <= 19; pos++) {
    printf("voto %i: %i\n", pos + 1, voti[pos]);
  }

  // calcola e stampa la media dei voti
  somma = 0;
  for (pos = 19; pos >= 0; pos--) {
  //for (pos = 0; pos < 20; pos++) {
    somma += voti[pos];
  }

  printf("La media dei voti e' %g\n",
	 somma / 20.0);

  return 0;
}
