#include <stdlib.h>
#include "television.h"
#include "list.h"

struct television *construct_television(const char *names[], int num_channels) {
  struct television *this = malloc(sizeof(struct television));
  this -> names = names;
  this -> num_channels = num_channels;
  this -> current_channel = 0;
  this -> undos = NULL;

  return this;
}

void destruct_television(struct television *this) {
  free(this);
}

void set_channel(struct television *this, int channel) {
  this -> undos = construct_list(this -> current_channel, this -> undos);
  this -> current_channel = channel;
}

const char *toString(struct television *this) {
  return this -> names[this -> current_channel];
}

void undo(struct television *this) {
  struct list *temp;

  if (this -> undos) {
    // salviamo la testa della lista
    temp = this -> undos;

    // eliminiamo la testa della lista
    this -> current_channel = this -> undos -> data;
    this -> undos = this -> undos -> next;

    // liberiamo la memoria occupata dalla testa della lista
    free(temp);
  }
}
