/* Chiede un anno e dice se è bisestile */

#include <stdio.h>

int main(void) {
  int anno;

  printf("Inserisci l'anno: ");
  scanf("%i", &anno);

  if (anno % 4 == 0 && (anno % 100 != 0 || anno % 400 == 0))
    printf("%i e' bisestile\n", anno);
  else
    printf("%i non e' bisestile\n", anno);

  return 0;
}
