#include <stdio.h>

int main(void) {
  int ore, minuti, secondi;

  do {
    printf("ore: ");
    scanf("%i", &ore);
  }
  while (ore < 0 || ore > 23);

  do {
    printf("minuti: ");
    scanf("%i", &minuti);
  }
  while (minuti < 0 || minuti > 59);

  do {
    printf("secondi: ");
    scanf("%i", &secondi);
  }
  while (secondi < 0 || secondi > 59);

  printf("Stati Uniti: %02i:%02i:%02i%s\n", ore % 12 ? ore % 12 : 12, minuti, secondi, ore / 12 ? "PM" : "AM");
  printf("Italia: %02i:%02i:%02i\n", ore, minuti, secondi);

  return 0;
}
