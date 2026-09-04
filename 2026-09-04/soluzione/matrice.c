/*
  Data una matrice A di caratteri NxN e una matrice M di interi NxN,
  contenente esclusivamente i valori 1, 0 e -1, scrivere un programma
  che popola una matrice B di interi NxN tale che, per ogni elemento (i,j):

  B(i,j) = 1 se M(i,j) = 1 e A(i,j) è un carattere alfabetico maiuscolo;
  B(i,j) = 0 se M(i,j) = 0 e A(i,j) è un carattere numerico che, convertito nel corrispondente valore intero, risulta pari;
  B(i,j) = -1 se M(i,j) = -1 e A(i,j) è un carattere speciale (cioè non alfabetico e non numerico);
  in tutti gli altri casi, B(i,j) = 99.

Si consideri ad esempio il seguente contenuto di A e M:

A =
a	b	c	2	1
4	F	4	1	.
.	4	a	z	0
!	A	B	%	!
-	b	r	9	1


M =
0	1	-1	0	1
0	1	1	0	-1
-1	0	1	1	0
1	0	-1	-1	0
0	1	1	-1	1


La matrice B conterrà i seguenti valori:

B =
99	99	99	0	99
0	1	99	99	-1
-1	0	99	99	0
99	99	99	-1	99
99	99	99	99	99
*/

#include <stdio.h>

#define N 5

int main(){
  char A[N][N];
  int M[N][N];
  int B[N][N];
  int i, j, x;
	
  for( i = 0; i < N; i++ ){
    for( j = 0; j < N; j++ ){
      scanf( " %c", &A[i][j] );
    }
  }
	
  for( i = 0; i < N; i++ ){
    for( j = 0; j < N; j++ ){
      scanf( "%d", &M[i][j] );
    }
  }
	
  for( i = 0; i < N; i++ ){
    for( j = 0; j < N; j++ ){
      if( M[i][j] == 1 && A[i][j] >= 'A' && A[i][j] <= 'Z' ){				
	B[i][j] = 1;		                
      } else if( M[i][j] == 0 && A[i][j] >= '0' && A[i][j] <= '9' ) {
	x = A[i][j] - '0';
	if( x % 2 == 0 ){
	  B[i][j] = 0;
	} else {
	  B[i][j] = 99;
	}
	
      } else if( M[i][j] == -1 && 
		 !( ( A[i][j] >= '0' && A[i][j] <= '9') ||
		    ( A[i][j] >= 'A' && A[i][j] <= 'Z') ||
		    ( A[i][j] >= 'a' && A[i][j] <= 'z')) ) {
	B[i][j] = -1;
      } else {
	B[i][j] = 99;
      }
    }
  }
  
  for( i = 0; i < N; i++ ){
    for( j = 0; j < N; j++ ){
      printf( "%d ", B[i][j] );
    }
    printf( "\n");
  }
  return 0;
}
