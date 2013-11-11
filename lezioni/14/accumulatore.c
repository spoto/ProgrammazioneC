#include <stdio.h>

int main(void) {
  float accumulatore = 0.0f;
  float numero;
  char operatore;

  do {
    scanf("%f %c", &numero, &operatore);

    switch (operatore) {
    case 'S':
      accumulatore = numero;
      break;
    case '+':
      accumulatore += numero;
      break;
    case '-':
      accumulatore -= numero;
      break;
    case '*':
      accumulatore *= numero;
      break;
    case '/':
      if (numero == 0.0f)
	printf("Divisione per 0 impossibile\n");
      else
	accumulatore /= numero;

      break;
    case 'E':
      break;
    default:
      printf("Operazioni disponibili: + - * / S E\n");
      break;
    }

    printf("= %f\n", accumulatore);
  }
  while (operatore != 'E');

  return 0;
}
