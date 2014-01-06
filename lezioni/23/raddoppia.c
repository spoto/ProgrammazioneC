#include <stdio.h>

// raddoppia gli elementi dell'array passato come parametro
// comporta side-effect sull'array!
void raddoppia(int array[], int size);
int main(void);

void raddoppia(int array[], int size) {
  int pos;

  for (pos = 0; pos < size; pos++)
    array[pos] *= 2;
}

int main(void) {
  int array[5] = { 8, 11, 2, -4, 8 };

  raddoppia(array, 5);

  printf("%i %i %i %i %i\n",
	 array[0],
	 array[1],
	 array[2],
	 array[3],
	 array[4]);

  return 0;
}
