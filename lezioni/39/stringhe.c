#include <stdio.h>

int lunghezza(char s[]) {
  int l = 0;

  while (s[l] != '\0')
    l++;

  return l;
}

int lunghezza2(char *s) {
  int l = 0;

  while (*s++)
    l++;

  return l;
}

int lunghezza3(char *s) {
  char *start = s;

  while (*s++);

  return --s - start;
}

void string_copy(char dest[], char src[]) {
  int pos = 0;

  do {
    dest[pos] = src[pos];
  }
  while (src[pos++] != '\0');
}

void string_copy2(char *dest, char *src) {
  int pos = 0;

  do {
    *(dest + pos) = *(src + pos);
  }
  while (*(src + pos++) != '\0');
}

void string_copy3(char *dest, char *src) {
  do {
    *dest++ = *src;
  }
  while (*src++);
}

void string_copy4(char *dest, char *src) {
  while (*dest++ = *src++);
}

// incrementa tutti i caratteri
// alfabetici
void increase(char s[]) {
  int pos;

  for (pos = 0; s[pos] != '\0'; pos++)
    if (s[pos] >= 'a' && s[pos] <= 'z')
      s[pos]++;
}

void increase2(char *s) {
  int pos;

  for (pos = 0; *(s + pos) != '\0'; pos++)
    if (*(s + pos) >= 'a' && *(s + pos) <= 'z')
      (*(s + pos))++;
}

void increase3(char *s) {
  while (*s != '\0') {
    if (*s >= 'a' && *s <= 'z')
      (*s)++;

    s++;
  }
}

int main(void) {
  char s[] = { 'c', 'i', ' ', 'o', '\0' };
  char dest[10];

  string_copy4(dest, s);

  printf("%s\n", dest);

  return 0;
}
