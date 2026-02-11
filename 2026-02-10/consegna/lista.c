#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define END "END"

typedef struct nodo{
  int palindroma;
  int cifre;
  int maiuscole;
  struct nodo *next;
} node;

// prototipi, e' possibile aggiungere funzioni
void visualizza(node *);
int palindroma(char *);
int cifre(char *);
int maiuscole(char *);
node *inserisciincoda(node *, int, int, int);

int main() {
  node *l = NULL;
  char val[30+1];

  scanf("%s",val);
  while (strcmp(val,END) != 0) {
    int p = palindroma(val);
    int c = cifre(val);
    int m = maiuscole(val);
    l = inserisciincoda(l, p, c, m);
    scanf("%s", val);
  }
	
  visualizza(l);
  return 0;
}

void visualizza(node* lista) {
  while (lista != NULL){
    if (lista->next != NULL)
      printf( "{%d, %d, %d} -> ", lista->palindroma, lista->cifre, lista->maiuscole );
    else
      printf( "{%d, %d, %d}", lista->palindroma, lista->cifre, lista->maiuscole );
    lista = lista->next;
  }
  printf("\n");
}

node *inserisciincoda(node *l, int pal, int cif, int mai) {	
}

int palindroma(char *s) {
}

int cifre(char *s) {    
}

int maiuscole(char* s) {	
}

