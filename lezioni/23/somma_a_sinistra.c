#include <stdio.h>

void somma_a_sinistra(int array[], int size);
int main(void);

// ogni elemento diventa la somma sua e degli elementi
// che gli stavano a sinistra
void somma_a_sinistra(int array[], int size) {
  int pos;

  for (pos = 1; pos < size; pos++)
    array[pos] += array[pos - 1];
}

int main(void) {
  int array[5] = { 8, 11, 2, -4, 8 };

  somma_a_sinistra(array, 5);
  // è diventato { 8, 19, 21, 17, 25 }

  printf("%i %i %i %i %i\n",
	 array[0],
	 array[1],
	 array[2],
	 array[3],
	 array[4]);

  return 0;
}
