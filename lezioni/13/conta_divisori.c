// chiede un numero intero positivo all'utente e
// stampa il numero dei suoi divisori interi positivi;
// se il numero non è positivo deve richiederlo

#include <stdio.h>

int main(void) {
  int numero;
  int numero_dei_divisori;
  int i;

  // legge numero: deve essere intero positivo
  do {
    printf("Inserisci il numero positivo: ");
    scanf("%i", &numero);
  }
  while (numero <= 0);

  // calcola quanti divisori interi positivi ha numero
  for (i = 1, numero_dei_divisori = 0;
       i <= numero; i++)
    if (numero % i == 0)
      numero_dei_divisori++;

  // stampa il numero di tali divisori
  if (numero_dei_divisori != 1) {
    printf("Il numero %i ha %i divisori interi\n",
	 numero, numero_dei_divisori);
    // stampa se il numero è primo o meno
    if (numero_dei_divisori == 2)
      printf("Il numero %i e' primo\n", numero);
    else
      printf("Il numero %i non e' primo\n", numero);    
  }
  else {
    printf("Il numero %i ha 1 divisore intero\n",
	   numero);
    printf("Il numero %i non e' primo\n", numero);
  }
 
  return 0;
}
