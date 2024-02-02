static int is_prime(int n);

int next_prime() {
  static int last = 2;

  int result = last;

  for (++last; !is_prime(last); last++);

  return result;
}

static int is_prime(int n) {
  int d;

  for (d = 2; d < n; d++)
    if (n % d == 0)
      return 0;

  return n >= 2;
}
