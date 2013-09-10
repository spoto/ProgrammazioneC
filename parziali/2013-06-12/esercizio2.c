#include <stdlib.h>
#include "list.h"

struct list *construct_list_from_string(const char *s) {
  return *s ? construct_list(*s, construct_list_from_string(s + 1)) : NULL;
}
