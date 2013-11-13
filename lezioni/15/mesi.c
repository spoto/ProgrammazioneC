#include <stdio.h>

int main(void) {
  int mese;
  int anno;

  do {
    printf("mese: ");
    scanf("%i", &mese);
    printf("anno: ");
    scanf("%i", &anno);
  }
  while (mese < 1 || mese > 12 || anno < 1600);

  switch (mese) {
  case 1: printf("gennaio"); break;
  case 2: printf("febbraio"); break;
  case 3: printf("marzo"); break;
  case 4: printf("aprile"); break;
  case 5: printf("maggio"); break;
  case 6: printf("giugno"); break;
  case 7: printf("luglio"); break;
  case 8: printf("agosto"); break;
  case 9: printf("settembre"); break;
  case 10: printf("ottobre"); break;
  case 11: printf("novembre"); break;
  case 12: printf("dicembre"); break;
  }

  printf(" %i", anno);

  switch (mese) {
  case 2:
    printf(" ha %i giorni\n", (anno % 400 == 0 || (anno % 4 == 0 && anno % 100 != 0)) ? 29 : 28);
    break;
  case 1: case 3: case 5: case 7: case 8: case 10: case 12: printf(" ha 31 giorni\n"); break;
  default: printf(" ha 30 giorni\n"); break;
  }

  return 0;
}
