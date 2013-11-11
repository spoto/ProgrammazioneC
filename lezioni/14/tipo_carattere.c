// legge un carattere da tastiera
// e determina se è una lettera maiuscola
// o una lettera minuscola
// oppure una cifra decimale

#include <stdio.h>

int main(void) {
  char carattere;

  printf("Inserisci un carattere: ");
  scanf("%c", &carattere);

  // determiniamo il tipo del carattere
  if (carattere >= 'A' && carattere <= 'Z')
    printf("Hai inserito una lettera maiuscola\n");
  else if (carattere >= 'a' && carattere <= 'z')
    printf("Hai inserito una lettera minuscola\n");
  else if (carattere >= '0' && carattere <= '9')
    printf("Hai inserito una cifra decimale\n");
  else
    printf("Non hai inserito ne' una cifra ne' una lettera\n");

  return 0;
}
