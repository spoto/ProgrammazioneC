#include <stdlib.h>
#include "list.h"

struct list *doppie(struct list *this) {
  if (!this || !this->tail)
    return NULL;
  else if (this->head == this->tail->head)
    return construct_list
      (this->head, construct_list(this->head, doppie(this->tail->tail)));
  else
    return doppie(this->tail);						    
}
