#include <stdio.h>

// cerca un sottoarray di arr (cioe' una porzione contigua di arr)
// i cui elementi abbiano somma massima; ritorna la posizione di inizio di tale
// sottoarray tramite start (incluso) e la posizione di fine di tale
// sottoarray tramite end (escluso).
void max_subarray(int arr[], int length, int *start, int *end) {
  // inizialmente, il sottoarray di somma massimo e' quello vuoto
  // all'inizio dell'array, i cui elementi hanno somma zero
  int max = 0;
  *start = *end = 0;

  // poi consideriamo tutti gli altri sottoarray per vedere se qualcuno
  // di essi ha somma maggiore
  for (int i = 0; i < length; i++)
    for (int j = i, sum = 0; j < length; j++) {
      sum += arr[j];
      if (sum > max) {
	max = sum;
	*start = i;
	*end = j + 1;
      }
    }
}

int main(void) {
  int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int start, end;
  max_subarray(arr, 9, &start, &end);
  printf("Un sottoarray di somma massima e': ");
  for (int pos = start; pos < end; pos++)
    printf("%i ", arr[pos]);
  printf("\n");
  return 0;
}
