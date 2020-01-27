int has_local_max(int arr[], int length, int how_many) {
  int count = 0;
  for (int pos = 0; pos < length; pos++)
    if ((pos == 0 || arr[pos - 1] < arr[pos]) &&
	(pos == length - 1 || arr[pos] > arr[pos + 1]))
      count++;
  
  return count >= how_many;
}
