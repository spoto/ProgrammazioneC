#include <stdio.h>
#include "myatoi.h"

void stampa_myatoi(char *s) {
  printf("myatoi(\"%s\") = %li\n", s, myatoi(s)); 
}

int main(void) {
  stampa_myatoi("12345");
  stampa_myatoi("012345");
  stampa_myatoi("54321");
  stampa_myatoi("543210");
  stampa_myatoi("192837465");
  stampa_myatoi("23344556678026");
  stampa_myatoi("");

  return 0;
}
