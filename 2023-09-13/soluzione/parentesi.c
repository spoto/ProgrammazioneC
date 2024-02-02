#include <stdio.h>
#include <stdlib.h>

void init_random(char arr[], int length) {
  for (int sx = 0, dx = length - 1; sx < dx; sx++, dx--) {
    switch (rand() % 3) {
    case 0: arr[sx] = '('; arr[dx] = ')'; break;
    case 1: arr[sx] = '{'; arr[dx] = '}'; break;
    case 2: arr[sx] = '['; arr[dx] = ']'; break;
    }
  }
}

// funzione ausiliaria, controlla che c1 sia una parentesi aperta, chiusa da c2
int apre_chiude(char c1, char c2) {
  return (c1 == '(' && c2 == ')') ||
    (c1 == '{' && c2 == '}') ||
    (c1 == '[' && c2 == ']');
}

int struttura_di_parentesi(char arr[], int length) {
  if (length == 0)
    return 1;
  else
    return apre_chiude(arr[0], arr[length - 1]) && struttura_di_parentesi(arr + 1, length - 2);
}
