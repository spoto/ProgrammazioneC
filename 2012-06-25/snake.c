#include <stdlib.h>
#include "snake.h"

// funzione privata
static int posiziona(struct snake *this, int x, int y);

struct snake *construct_snake() {
  struct snake *this = malloc(sizeof(struct snake));
  int i, j;

  // creiamo la configurazione iniziale
  for (i = 0; i < 21; i++)
    for (j = 0; j < 21; j++)
      if (i == 0 || j == 0 || i == 20 || j == 20)
	this->caselle[i][j] = '*';
      else
	this->caselle[i][j] = ' ';

  // posizioniamo il serpente al centro
  this->caselle[this->x = 10][this->y = 10] = 'X';

  return this;
}

void destruct_snake(struct snake *this) {
  free(this);
}

// ritorna falso se la casella era gia' occupata
static int posiziona(struct snake *this, int x, int y) {
  if (this->caselle[x][y] != ' ')
    return 0;
  else {
    // la vecchia posizione del serpente viene
    // occupata dalla scia
    this->caselle[this->x][this->y] = '*';

    return this->caselle[this->x = x][this->y = y] = 'X';
  }
}

int goLeft(struct snake *this) {
  return posiziona(this, this->x - 1, this->y);
}

int goRight(struct snake *this) {
  return posiziona(this, this->x + 1, this->y);
}

int goUp(struct snake *this) {
  return posiziona(this, this->x, this->y - 1);
}

int goDown(struct snake *this) {
  return posiziona(this, this->x, this->y + 1);
}

char *toString(struct snake *this) {
  char *res = malloc((22 * 21 + 1) * sizeof(char));
  char *start = res;
  int x, y;

  for (y = 0; y < 21; y++) {
    for (x = 0; x < 21; x++)
      *res++ = this->caselle[x][y];

    *res++ = '\n';
  }

  *res = '\0';

  return start;
}

