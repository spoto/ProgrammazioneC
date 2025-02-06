#include <stdio.h>

void processa(int arr[], int length, int threshold) {
	for (int pos = 0; pos < length; pos++)
		if (threshold <= arr[pos])
			arr[pos] = 0;
}

void print(int arr[], int length) {
	for (int pos = 0; pos < length; pos++)
	  printf("%i ", arr[pos]);

	printf("\n");
}

int main(void) {
	int arr1[] = { 3, 5, 5, 15, 11, 30, 87 };
	processa(arr1, 7, 13);
	print(arr1, 7);

	int arr2[] = { -3, 2, 5, 20, -80, 21, 7, -11, -40 };
	processa(arr2, 9, -1);
	print(arr2, 9);

	return 0;
}
