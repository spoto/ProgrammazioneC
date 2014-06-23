#ifndef VOCABOLARIO_H
#define VOCABOLARIO_H

struct voce {
  char *italiano;
  char *inglese;
};

#define SIZE 100

struct vocabolario {
  struct voce voci[SIZE];
  int voci_usate; // quante voci del vocabolario sono gia' state usate
};

struct vocabolario *construct_vocabolario();
void destroy_vocabolario(struct vocabolario *this);
void print_vocabolario(struct vocabolario *this);
void add_in_vocabolario(struct vocabolario *this, char *italiano, char *inglese);
char *cerca_dallitaliano(struct vocabolario *this, char *italiano);
char *cerca_dallinglese(struct vocabolario *this, char *inglese);
void sort_italiano(struct vocabolario *this);

#endif
