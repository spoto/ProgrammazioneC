#include <stdio.h>

void f(int *p){
  *p = 5;
}

void g(int *p){
  int i = 12;
  p = &i;
}

int main(void){
  int n = 8;
  int *p = &n;
  printf( "Il valore puntato da p e' uguale a %d.\n", *p ); // *p = 8
  f(p);
  printf( "Il valore puntato da p e' uguale a %d.\n", *p);  // *p = 5
  g(p);
  printf( "Il valore puntato da p e' uguale a %d.\n", *p);  // *p = 5
}