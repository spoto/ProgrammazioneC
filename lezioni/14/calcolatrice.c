// chiede all'utente di inserire espressioni del tipo:
// float operatore float
// dove l'operatore è una delle 4 operazioni aritmetiche
// e ne calcola il risultato a video

#include <stdio.h>

int main(void) {
  float sinistra, destra, risultato;
  char operatore;

  do {
    scanf("%f %c %f", &sinistra, &operatore, &destra);

    switch (operatore) {
    case '+':
      risultato = sinistra + destra;
      break;
    case '-':
      risultato = sinistra - destra;
      break;
    case '*':
      risultato = sinistra * destra;
      break;
    case '/':
      risultato = sinistra / destra;
      break;
    default:
      printf("Operatore sconosciuto: riprova\n");
      break;
    }
  }
  while (operatore != '+' &&
	 operatore != '-' &&
	 operatore != '*' &&
	 operatore != '/');

  printf("%.3f %c %.3f = %.3f\n",
	 sinistra, operatore, destra, risultato);

  return 0;
}
