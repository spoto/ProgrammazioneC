#ifndef SNAKE_H
#define SNAKE_H

struct snake {
  char caselle[21][21];  // le caselle del gioco: spazio, asterisco o X
  int x;  // l'ascissa della testa del serpente adesso
  int y;  // l'ordinata della testa del serpente adesso
};

struct snake *construct_snake();
void destruct_snake(struct snake *this);
int goLeft(struct snake *this);
int goRight(struct snake *this);
int goUp(struct snake *this);
int goDown(struct snake *this);
char *toString(struct snake *this);

#endif
