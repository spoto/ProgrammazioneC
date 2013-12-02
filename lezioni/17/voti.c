#include <stdio.h>

int main(void) {
  int persone_che_hanno_preso[31];
  int voto;
  int contatore = 1;
  int somma_voti, numero_voti;

  // inizializzo a 0 il vettore
  for (voto = 0; voto <= 30; voto++)
    persone_che_hanno_preso[voto] = 0;

  // leggi da tastiera i voti
  do {
    printf("voto %i: ", contatore);
    scanf ("%i", &voto);
    if (voto >= 0 && voto <= 30) {
      persone_che_hanno_preso[voto]++;
      contatore++;
    }
  }
  while (voto >= 0);

  // stampo i risultati
  for (voto = 0; voto <= 30; voto++)
    if (persone_che_hanno_preso[voto] > 0)
      printf("%i person%s preso %i\n",
	     persone_che_hanno_preso[voto],
	     persone_che_hanno_preso[voto] == 1 ? "a ha" : "e hanno",
	     voto);

  // calcola somma_voti e numero_voti
  somma_voti = numero_voti = 0;
  for (voto = 0; voto <= 30; voto++) {
    somma_voti += voto * persone_che_hanno_preso[voto];
    numero_voti += persone_che_hanno_preso[voto];
  }

  // stampa il voto medio
  printf("voto medio: %f\n", (float) somma_voti / numero_voti);
  
  return 0;
}
