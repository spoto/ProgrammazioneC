struct List {
  int head;
  struct List *tail;
};

struct List *create(int head, struct List *tail);
void print(struct List *this);
struct List *from(int arr[], int length);
struct List *filter(struct List *this, int threshold);
struct List *duplicate(struct List *this);

