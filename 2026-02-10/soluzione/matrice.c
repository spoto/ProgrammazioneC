#include <stdio.h>
#define N 3
#define M 4

int main(){
  int A[N][M];
  int X[N];

  /* Lettura della matrice */
  for (int i = 0; i < N; i++)
    for (int j = 0; j < M; j++)
      scanf("%d", &A[i][j]);

  /* Inizializzazione del vettore X */
  for (int i = 0; i < N; i++) {
    X[i] = 1;  
    for (int j = 0; j < M && X[i]; j++) {

      /* Controllo delle cifre del numero */
      int cifrapari = 0;
      for (int num = A[i][j]; num > 0 && !cifrapari; num /= 10) {
	int cifra = num % 10;
	if (cifra % 2 == 0)
	  cifrapari = 1;
      }

      /* Se un numero non ha cifre pari, la riga non soddisfa la proprietà */
      if (!cifrapari)
	X[i] = 0;
    }
  }

  /* Stampa del vettore X */
  for (int i = 0; i < N; i++)
    printf("%d ", X[i]);

  return 0;
}
