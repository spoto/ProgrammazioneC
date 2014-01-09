#include <stdio.h>

#define SIZE 30000

void init_random(int array[], int length);
int index_of_min(int array[], int start, int length);
void min_sort(int array[], int length);
void bubble_sort(int array[], int length);
int swap_pairs(int array[], int length);
void swap(int array[], int i, int j);
int main(void);

void init_random(int array[], int length) {
  int pos;

  for (pos = 0; pos < length; pos++)
    array[pos] = rand();
}

void swap(int array[], int i, int j) {
  int temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

int index_of_min(int array[], int start, int length) {
  int res = start;
  int pos;

  for (pos = start + 1; pos < length; pos++)
    if (array[pos] < array[res])
      res = pos;

  return res;
}

void min_sort(int array[], int length) {
  int start, min_pos;

  for (start = 0; start < length - 1; start++) {
    min_pos = index_of_min(array, start, length);
    swap(array, start, min_pos);
  }
}

int swap_pairs(int array[], int length) {
  int pos;
  int swapped = 0; // falso

  for (pos = 0; pos < length - 1; pos++)
    if (array[pos] > array[pos + 1]) {
      swap(array, pos, pos + 1);
      swapped = 1; // vero
    }

  return swapped;
}

void bubble_sort(int array[], int length) {
  while (swap_pairs(array, length));
}

int main(void) {
  int array[SIZE];
  double start, end;

  srand(time(NULL));

  init_random(array, SIZE);

  start = clock();
  bubble_sort(array, SIZE);
  end = clock();
  printf("Tempo per il bubble sort: %.1f secondi\n", (end - start) / 1000000.0);

  start = clock();
  min_sort(array, SIZE);
  end = clock();
  printf("Tempo per il min sort: %.1f secondi\n", (end - start) / 1000000.0);

  return 0;
}
