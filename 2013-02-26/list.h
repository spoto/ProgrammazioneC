// una lista di interi
struct list {
  int head;
  struct list *tail;
};

struct list *construct(int head, struct list *tail);
struct list *inner(struct list *this);
void print_list(struct list *this);
