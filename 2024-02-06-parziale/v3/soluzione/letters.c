#include <stdio.h>
#include <stdlib.h>

int is_capital(char c) {
  return c >= 'A' && c <= 'Z';
}

// inizializza arr, lungo length, con lettere casuali dell'alfabeto
// inglese, maiuscole o minuscole, in modo tale che non ci siano
// mai due maiuscole o due minuscole di seguito; non randomizza
// la sequenza casuale con srand(time(NULL)): ci pensa il main
void init(char arr[], int length) {
  for (int pos = 0; pos < length; pos++) {
    do {
      arr[pos] = (rand() % 2 ? 'a' : 'A') + rand() % 26;
    }
    while (pos > 0 && is_capital(arr[pos]) == is_capital(arr[pos - 1]));
  }
}

// stampa (senza fare spazi in mezzo) i caratteri di arr, lungo length,
// e va a capo alla fine
void print(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);

  printf("\n");
}

// modifica l'array arr, lungo length, in modo che le vocali
// vengano sostituite con la vocale successiva, in modo ciclico
// (cioe' la 'a' diventa una 'e', la 'e' diventa una 'i' ecc;
// la 'u' diventa una 'a'; stesse modifiche per le vocali maiuscole)
void rotate_vowels(char arr[], int length) {
  for (int pos = 0; pos < length; pos++)
    if (arr[pos] == 'a')
      arr[pos] = 'e';
    else if (arr[pos] == 'e')
      arr[pos] = 'i';
    else if (arr[pos] == 'i')
      arr[pos] = 'o';
    else if (arr[pos] == 'o')
      arr[pos] = 'u';
    else if (arr[pos] == 'u')
      arr[pos] = 'a';
    else if (arr[pos] == 'A')
      arr[pos] = 'E';
    else if (arr[pos] == 'E')
      arr[pos] = 'I';
    else if (arr[pos] == 'I')
      arr[pos] = 'O';
    else if (arr[pos] == 'O')
      arr[pos] = 'U';
    else if (arr[pos] == 'U')
      arr[pos] = 'A';
}
