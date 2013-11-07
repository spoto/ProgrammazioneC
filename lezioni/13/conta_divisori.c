#include <stdio.h>

int main(void) {
  int num;
  int numero_divisori;
  int candidato;

  do {
    printf("Inserisci un numero >= 1: ");
    scanf("%i", &num);
  }
  while (num < 1);

  for (candidato = 1, numero_divisori = 0;
       candidato <= num; candidato++)
    if (num % candidato == 0)
      // ho trovato un divisore!
      numero_divisori++;

  if (numero_divisori == 1)
    printf("Il numero %i ha 1 divisore\n", num);
  else if (numero_divisori <= 5)
    printf("Il numero %i ha %i divisori\n",
	   num, numero_divisori);
  else
    printf("Il numero %i ha troppi divisori\n", num);

  // i numeri primi hanno esattamente due divisori
  if (numero_divisori == 2)
    printf("ed e' un numero primo\n");
  else
    printf("e non e' un numero primo\n");

  return 0;
}
