int sum(int arr[], int length) {
  int pos;
  int result = 0;
  for (pos = 1; pos < length; pos++)
    if (arr[pos - 1] % 2 != 0)
      result += arr[pos];

  return result;
}
