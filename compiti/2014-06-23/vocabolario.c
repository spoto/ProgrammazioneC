#include <stdlib.h>
#include <stdio.h>
#include "vocabolario.h"

struct vocabolario *construct_vocabolario() {
  struct vocabolario *this = malloc(sizeof(struct vocabolario));
  this->voci_usate = 0;

  return this;
}

void destroy_vocabolario(struct vocabolario *this) {
  free(this);
}

void print_vocabolario(struct vocabolario *this) {
  int pos;

  printf("%-20s | %-20s\n", "italiano", "inglese");
  printf("%-20s | %-20s\n", "--------", "-------");

  for (pos = 0; pos < this->voci_usate; pos++)
      printf("%-20s | %-20s\n", this->voci[pos].italiano, this->voci[pos].inglese);
}

void add_in_vocabolario(struct vocabolario *this, char *italiano, char *inglese) {
  int usate = this->voci_usate;

  if (usate < SIZE) {
    this->voci[usate].italiano = italiano;
    this->voci[usate].inglese = inglese;
    this->voci_usate++;
  }
}

char *cerca_dallitaliano(struct vocabolario *this, char *italiano) {
  int pos;

  for (pos = 0; pos < this->voci_usate; pos++)
    if (strcmp(this->voci[pos].italiano, italiano) == 0)
      return this->voci[pos].inglese;

  return NULL; // non c'e'
}

char *cerca_dallinglese(struct vocabolario *this, char *inglese) {
  int pos;

  for (pos = 0; pos < this->voci_usate; pos++)
    if (strcmp(this->voci[pos].inglese, inglese) == 0)
      return this->voci[pos].italiano;

  return NULL; // non c'e'
}

static int swap(struct vocabolario *this) {
  struct voce temp;
  int swapped = 0;
  int pos;

  for (pos = 0; pos < this->voci_usate - 1; pos++)
    if (strcmp(this->voci[pos].italiano, this->voci[pos + 1].italiano) > 0) {
      temp = this->voci[pos];
      this->voci[pos] = this->voci[pos + 1];
      this->voci[pos + 1] = temp;
      swapped = 1;
    }

  return swapped;
}

void sort_italiano(struct vocabolario *this) {
  while (swap(this));
}
