#ifndef NOTE_H
#define NOTE_H

struct nota {
  int semitono;
};

struct nota *construct_nota(int semitono);
void destroy_nota(struct nota *this);
void print_nota_it(struct nota *this);
void print_nota_uk(struct nota *this);
void incrementa_nota(struct nota *this, int inc);
struct nota *nota_incrementata(struct nota *this, int inc);

#endif
