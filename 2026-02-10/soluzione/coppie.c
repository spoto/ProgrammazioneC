#include <stdio.h>

/* prototipi delle funzioni */
int somma(int);
int left(int);

int main() {
  int count = 0, num, prev;

  scanf("%d", &prev);
  while (prev > 0) {
    scanf("%d", &num);

    if (num > 0 && somma(prev) == left(num))
      count++;

    prev = num;
  }
		
  printf("%d\n", count);
  return 0;
}

/* funzione che restituisce la somma delle cifre decimali di un numero intero positivo */
int somma(int n) {
   int s = 0;
    while (n > 0) {
        s += n % 10;
        n /= 10;
    }
    return s;
}

// funzione RICORSIVA che restituisce la cifra decimale piu' significativa di un numero intero positivo
int left(int n) {
  if (n / 10 == 0) return n % 10;
  else return left(n / 10);	
}
