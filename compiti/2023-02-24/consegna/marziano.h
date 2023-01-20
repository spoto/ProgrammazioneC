// un nodo di una lista di caratteri
struct element_t {
  char value;
  struct element_t *next;
};

void init_random(char arr[], int length);
void print(char arr[], int length);
void ordina_marziano(char arr[], int length);
struct element_t *vocali_non_ripetute(char arr[], int length);
void print_list(struct element_t *l);
