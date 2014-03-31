#include <stdio.h>

struct entry {
  char word[20];
  char definition[100];
};

// restituisce la posizione di key nel dictionary
// se key non c'è restituisce -1

int compare_strings(const char s1[], const char s2[]) {
  int pos = 0;

  while (s1[pos] == s2[pos] && s1[pos])
    pos++;

  return s1[pos] - s2[pos];
}

int lookup_linear
    (char key[], struct entry dictionary[], int length) {

  int pos;

  for (pos = 0; pos < length; pos++)
    if (compare_strings(dictionary[pos].word, key) == 0)
      return pos;

  return -1; // non c'è
}

int lookup
    (char key[], struct entry dictionary[], int length) {

  int left = 0, right = length - 1, middle;
  int comp;

  while (left <= right) {
    middle = (left + right) / 2;
    comp = compare_strings(key, dictionary[middle].word);
    if (comp == 0)
      return middle;
    else if (comp < 0)
      right = middle - 1;
    else
      left = middle + 1;
  }

  return -1; // non c'è
}

int main(void) {
  struct entry dictionary[] = {
    { "automobile", "strumento di trasporto" },
    { "cane", "animale che abbaia spesso" },
    { "cattedra", "tavolo universitario" },
    { "computer", "strumento di calcolo automatico" },
    { "gatto", "animale peloso e miagolante" },
    { "lavagna", "supporto per scrittura a parete" },
    { "studente", "persona che studia molto" }
  };

  char key[20];

  printf("chiave da ricercare: ");
  scanf("%19s", key);

  printf("Si trova in posizione %i\n",
	 lookup(key, dictionary, 7));

  return 0;
}
