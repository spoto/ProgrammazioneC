struct list {
  char *head;
  struct list *tail;
};

void init(char arr[], int length);
struct list *create_list(char *s);
void free_list(struct list *l);
struct list *create_list2(char *s);
void free_list2(struct list *l);
void print_list(struct list *l);
