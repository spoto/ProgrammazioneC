// traduce un numero in un array che contiene le sue cifre
// espresse in una base arbitraria

#include <stdio.h>

void immissione_dati(void);
void calcolo_conversione(void);
void stampa_conversione(void);

int main(void) {
  immissione_dati();
  calcolo_conversione();
  stampa_conversione();
}

// variabili globali
long numberToConvert;
int base;
int indice;
char convertedDigits[64];

void immissione_dati(void) {
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
}

void calcolo_conversione(void) {
  // static: viene creato solo una volta quando parte il programma
  static const char baseDigits[16] = { '0', '1', '2', '3', '4', '5',
				'6', '7', '8', '9', 'A', 'B',
				'C', 'D', 'E', 'F' };

  // converte il numero nella base specificata
  indice = 0;
  do {
    convertedDigits[indice++] = baseDigits[numberToConvert % base];
    numberToConvert /= base;
  }
  while (numberToConvert != 0);
}

void stampa_conversione(void) {
  // visualizza il risultato in ordine inverso
  printf("Numero convertito: ");

  for (--indice; indice >= 0; indice--)
    printf("%c", convertedDigits[indice]);

  printf("\n");
}
