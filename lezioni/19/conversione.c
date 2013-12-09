// traduce un numero in un array che contiene le sue cifre
// espresse in una base arbitraria

#include <stdio.h>

int main(void) {
  const char baseDigits[16] = { '0', '1', '2', '3', '4', '5',
				'6', '7', '8', '9', 'A', 'B',
				'C', 'D', 'E', 'F' };
  char convertedDigits[64];
  long numberToConvert;
  int nextDigit, base, index;

  // legge il numero da convertire e la base di conversione
  do {
    printf("Numero positivo da convertire: ");
    scanf("%ld", &numberToConvert);
  }
  while (numberToConvert < 0);

  do {
    printf("Base (2-16): ");
    scanf("%i", &base);
  }
  while (base < 2 || base > 16);

  // converte il numero nella base specificata
  index = 0;
  do {
    convertedDigits[index++] = baseDigits[numberToConvert % base];
    numberToConvert /= base;
  }
  while (numberToConvert != 0);

  // visualizza il risultato in ordine inverso
  printf("Numero convertito: ");

  for (--index; index >= 0; index--)
    printf("%c", convertedDigits[index]);

  printf("\n");

  return 0;
}
