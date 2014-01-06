#include <stdio.h>

#define SIZE 30000

void init_random(int array[], int size);
// ordina gli elementi dell'array passato come parametro
// comporta side-effect sull'array!
void min_sort(int array[], int size);
void bubble_sort(int array[], int size);
int swap(int array[], int start, int size);
int main(void);

void init_random(int array[], int size) {
  int pos;

  for (pos = 0; pos < size; pos++)
    array[pos] = rand();
}

void min_sort(int array[], int size) {
  int pos, pos2, temp;

  for (pos = 0; pos < size - 1; pos++)
    for (pos2 = pos + 1; pos2 < size; pos2++)
      if (array[pos] > array[pos2]) {
        temp = array[pos];
        array[pos] = array[pos2];
        array[pos2] = temp;
      }
}

int swap(int array[], int start, int size) {
  int pos, temp;
  int swapped = 0; // falso

  for (pos = size - 2; pos >= start; pos--)
    if (array[pos] > array[pos + 1]) {
      temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      swapped = 1; // vero
    }

  return swapped;
}

void bubble_sort(int array[], int size) {
  int start = 0;

  while (swap(array, start++, size));
}

int main(void) {
  int array[SIZE];
  double start, end;

  srand(time(NULL));

  init_random(array, SIZE);

  start = clock();
  min_sort(array, SIZE);
  end = clock();
  printf("Tempo per il min sort: %.1f secondi\n", (end - start) / 1000000.0);

  start = clock();
  bubble_sort(array, SIZE);
  end = clock();
  printf("Tempo per il bubble sort: %.1f secondi\n", (end - start) / 1000000.0);

  return 0;
}
