#include <stdio.h>
#include "has_local_max.h"

int main(void) {
  int length;

  do {
    printf("Quanti elementi? ");
    scanf("%i", &length);
  }
  while (length < 0);
  
  int elements[length];
  
  for (int pos = 0; pos < length; pos++) {
    printf("elemento #%i: ", pos);
    scanf("%i", &elements[pos]);
  }
  
  int at_least_3 = has_local_max(elements, length, 3);
  if (at_least_3)
    printf("Ci sono almeno tre massimi locali\n");
  else
    printf("Ci sono meno di tre massimi locali\n");
  
  return 0;
}
