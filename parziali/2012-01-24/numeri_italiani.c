#include <stdio.h>

static int leggi(void);
static void stampa(const int numero);
static void stampa_aux(const int numero);
static void stampa_cifra(const int cifra);

int main(void) {
  int numero = leggi();

  stampa(numero);

  return 0;
}

static int leggi(void) {
  int numero;

  do {
    printf("inserisci un numero positivo: ");
    scanf("%d", &numero);
  }
  while (numero < 0);

  return numero;
}

static void stampa(const int numero) {
  if (numero == 0)
    printf("zero\n");
  else {
    stampa_aux(numero);
    printf("\n");
  }
}

static void stampa_aux(const int numero) {
  if (numero == 0)
    return;
  else {
    stampa_aux(numero / 10);
    stampa_cifra(numero % 10);
    printf(" ");
  }
}

static void stampa_cifra(const int cifra) {
  switch (cifra) {
  case 0: printf("zero"); break;
  case 1: printf("uno"); break;
  case 2: printf("due"); break;
  case 3: printf("tre"); break;
  case 4: printf("quattro"); break;
  case 5: printf("cinque"); break;
  case 6: printf("sei"); break;
  case 7: printf("sette"); break;
  case 8: printf("otto"); break;
  case 9: printf("nove"); break;
  }
}
