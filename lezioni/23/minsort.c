#include <stdio.h>

// ordina gli elementi dell'array passato come parametro
// comporta side-effect sull'array!
void ordina(int array[], int size);
int main(void);

void ordina(int array[], int size) {
  int pos, pos2, temp;

  for (pos = 0; pos < size - 1; pos++)
    for (pos2 = pos + 1; pos2 < size; pos2++)
      if (array[pos] > array[pos2]) {
	temp = array[pos];
	array[pos] = array[pos2];
	array[pos2] = temp;
      }
}

int main(void) {
  int array[5] = { 8, 11, 2, -4, 8 };

  ordina(array, 5);

  printf("%i %i %i %i %i\n",
	 array[0],
	 array[1],
	 array[2],
	 array[3],
	 array[4]);

  return 0;
}
