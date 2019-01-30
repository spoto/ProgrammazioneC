#include <stdio.h>  // serve per printf()
#include <stdlib.h> // serve per rand() e srand()
#include <time.h>   // serve per time()

void init_random(char arr[], int length) {
  srand(time(NULL));

  int pos;
  for (pos = 0; pos < length; pos++)
    arr[pos] = 'a' + rand() % ('z' - 'a');
}

void print(char arr[], int length) {
  int pos;
  for (pos = 0; pos < length; pos++)
    printf("%c", arr[pos]);

  printf("\n");
}

void swap(char arr[], int length) {
  int pos;
  for (pos = 0; pos < length - 1; pos += 2) {
    char temp = arr[pos];
    arr[pos] = arr[pos + 1];
    arr[pos + 1] = temp;
  }
}
