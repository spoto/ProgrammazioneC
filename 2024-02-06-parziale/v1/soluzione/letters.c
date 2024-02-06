#include <stdio.h>
#include <stdlib.h>

int is_vowel(char c) {
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
}

// inizializza arr, lungo length, con lettere casuali dell'alfabeto
// inglese, maiuscole o minuscole, in modo tale che non ci siano
// mai due vocali di seguito (si consideri la definizione italiana di
// vocale: aeiou, minuscole o maiuscole)
// non randomizza la sequenza casuale con srand(time(NULL)): ci pensa il main
void init(char arr[], int length) {
  for (int pos = 0; pos < length; pos++) {
    do {
      arr[pos] = (rand() % 2 ? 'a' : 'A') + rand() % 26;
    }
    while (pos > 0 && is_vowel(arr[pos]) && is_vowel(arr[pos - 1]));
  }
}

// stampa (senza fare spazi in mezzo) i caratteri di arr, lungo length,
// e va a capo alla fine
void print(char arr[], int length) {
  for(int pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);

  printf("\n");
}

// modifica l'array arr, lungo length, in modo che le lettere
// minuscole diventino maiuscole e viceversa
void invert(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    if ('a' <= arr[pos] && arr[pos] <= 'z')
      arr[pos] -= ('a' - 'A');
    else
      arr[pos] += ('a' - 'A');
}
