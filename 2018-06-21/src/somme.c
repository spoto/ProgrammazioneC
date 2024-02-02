#include <stdio.h>

void somme(int*, int);

int main( void ) {
  int arr[] = {5,2,10,6,8,9,7,5,6,7};
  int i, length = 10;

  somme( arr, length );
  
  for (i = 0; i < length; i++ ) {
    printf( "%i ", *(arr+i) );
  }
  return 0;
}

void somme( int *a, int length ){  
  int i;
  
  for (i = 2; i < length; i++)
    *(a+i) = *(a+i) + *(a+i-2);
}
