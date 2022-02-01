#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void input(int array[], int length) {
  // modifica l'array, lungo length, con valori inseriti dall'utente tramite la tastiera
  for (int pos = 0; pos < length; pos++) {
    printf("Inserisci l'elemento #%i: ", pos);
    scanf("%i", &array[pos]);
  }
}

void print(int array[], int length) {
  // stampa sul video l'array, lungo length, su una riga, andando a capo alla fine
  for (int pos = 0; pos < length; pos++)
    printf("%i ", array[pos]);

  printf("\n");
}

long factorial(long n) {
  if (n == 0)
    return 1;
  else
    return n * factorial(n - 1);
}

int is_factorion(long n) {
  // determina se n è un fattorione, cioè se n è uguale alla somma dei fattoriali delle proprie cifre.
  // Per esempio, 145 è un fattorione poiché 145=1!+4!+5!
  long sum = 0;
  for (int m = n; m > 0; m /= 10)
    sum += factorial(m % 10);

  return n == sum;
}

void christmas_tree(int n) {
  // la larghezza dell'albero: e' sempre un numero dispari
  int width;
  if (n < 3)
    width = 1 + 2 * n;
  else
    width = 3 + 2 * n / 3;

  for (int row = 0; row < n; row++) {
    // la larghezza della riga row-esima
    int row_width = 1 + 2 * (row % 3 + row / 3);

    for (int i = 1; i <= (width - row_width) / 2; i++)
      printf(" ");
    
    for (int i = 1; i <= row_width; i++)
      printf("*");

    printf("\n");
  }
}

void christmas_tree_decorated(int n) {
  srand(time(NULL));
  
  // la larghezza dell'albero: e' sempre un numero dispari
  int width;
  if (n < 3)
    width = 1 + 2 * n;
  else
    width = 3 + 2 * n / 3;

  for (int row = 0; row < n; row++) {
    // la larghezza della riga row-esima
    int row_width = 1 + 2 * (row % 3 + row / 3);

    for (int i = 1; i <= (width - row_width) / 2; i++)
      printf(" ");
    
    for (int i = 1; i <= row_width; i++)
      if (rand() % 10)
	printf("*");
      else
	printf("@");

    printf("\n");
  }
}
