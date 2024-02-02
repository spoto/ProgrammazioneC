void rotate_right(int arr[], int length) {
  if (length > 0) {
    int last = arr[length - 1];
    for (int pos = length - 2; pos >= 0; pos--)
      arr[pos + 1] = arr[pos];

    arr[0] = last;
  }
}
