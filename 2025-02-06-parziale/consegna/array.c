// aggiungete #include se servono

void processa(int arr[], int length, int threshold) {
  // modifica arr, lungo length, azzerando gli elementi che sono
  // maggiori o uguali a threshold
}

void print(int arr[], int length) {
  // stampa arr, lungo length, su una riga, separando gli elementi
  // con uno spazio e andando a capo alla fine
}

int main(void) { // gia' fatto, non modificate
  int arr1[] = { 3, 5, 5, 15, 11, 30, 87 };
  processa(arr1, 7, 13);
  print(arr1, 7);

  int arr2[] = { -3, 2, 5, 20, -80, 21, 7, -11, -40 };
  processa(arr2, 9, -1);
  print(arr2, 9);

  return 0;
}
