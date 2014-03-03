#include <stdio.h>
#include <stdlib.h>
#include "chart.h"

struct chart *construct_chart(void) {
  struct chart *this = malloc(sizeof(struct chart));
  int pos;

  for (pos = 0; pos < 10; pos++)
    this->titles[pos] = "-";

  return this;
}

void destroy_chart(struct chart *this) {
  free(this);
}

void print_chart(struct chart *this) {
  int pos;

  printf("song list\n");
  for (pos = 0; pos < 10; pos++)
    printf("[%i] %s\n", pos + 1, this->titles[pos]);
}

void set_song_title(struct chart *this, const char *title, int position) {
  this->titles[position - 1] = title;
}

int main(void) {
  struct chart *c = construct_chart();

  set_song_title(c, "O luna tua", 3);
  set_song_title(c, "Canzone stonata", 1);
  set_song_title(c, "Red submarine", 8);

  print_chart(c);

  return 0;
}
