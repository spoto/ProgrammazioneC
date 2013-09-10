#include "list.h"

struct television {
  const char **names;
  int num_channels;
  int current_channel;
  struct list *undos;
};

struct television *construct_television(const char *names[], int num_channels);
void destruct_television(struct television *this);
void set_channel(struct television *this, int channel);
const char *toString(struct television *this);
void undo(struct television *this);
