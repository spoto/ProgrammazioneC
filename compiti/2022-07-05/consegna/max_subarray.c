#include <stdio.h>

// cerca un sottoarray di arr (cioe' una porzione contigua di arr)
// i cui elementi abbiano somma massima; ritorna la posizione di inizio di tale
// sottoarray tramite start (incluso) e la posizione di fine di tale
// sottoarray tramite end (escluso).
void max_subarray(int arr[], int length, int *start, int *end) {
  // completare
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
