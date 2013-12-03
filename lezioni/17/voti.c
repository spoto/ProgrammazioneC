#include <stdio.h>

int main(void) {
  int voti[31] = { 0 };
  int voto;
  int pos;
  int num, den;

  do {
    printf("voto: ");
    scanf("%i", &voto);

    if (voto >= 0 && voto <= 30)
      voti[voto]++;
  }
  while (voto >= 0);

  for (pos = 0; pos < 31; pos++)
    printf("%i ", voti[pos]);

  printf("\n");

  for (voto = 0; voto < 31; voto++)
    if (voti[voto] > 0)
      printf("%i student%c ha%s preso %i %s\n",
	     voti[voto],
	     voti[voto] == 1 ? 'e' : 'i',
	     voti[voto] == 1 ? "" : "nno",
	     voto,
	     voto >= 18 ? "" : "(insufficiente)");

  // calcoliamo la media dei voti
  num = den = 0;
  for (voto = 0; voto < 31; voto++) {
    num += voti[voto] * voto;
    den += voti[voto];
  }
    
  printf("La media dei voti e': %g\n",
	 ((double) num) / den);

  return 0;
}
