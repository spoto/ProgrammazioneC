int al_massimo_due_di_seguito(const char *s) {
  while (*s) {
    if (*s == *(s + 1) && *s == *(s + 2))
      return 0; // falso

    s++;
  }

  return 1; // vero
}
