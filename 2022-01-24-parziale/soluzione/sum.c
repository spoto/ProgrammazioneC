int sum(int arr[], int length) {
  int somma = 0;
  for (int pos = 0; pos < length; pos++) {
    int sinistra = (pos == 0) ? 0 : arr[pos - 1];
    int destra = (pos == length - 1) ? 0 : arr[pos + 1];
    if (arr[pos] > sinistra + destra)
      somma += arr[pos];
  }

  return somma;
}
