// un nodo di una lista di caratteri
struct element_t {
  char value;
  struct element_t *next;
};

void init_random(char arr[], int length);
void print(char arr[], int length);
void ordina_vulcaniano(char arr[], int length);
struct element_t *non_ripetuti(char arr[], int length);
void print_list(struct element_t *l);
