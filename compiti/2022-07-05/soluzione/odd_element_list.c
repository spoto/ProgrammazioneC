#include <stdio.h>
#include <stdlib.h>

struct element_t {
  int value;
  struct element_t *next;
};

struct element_t *create_odd_list(const char *filename);
void print_list(struct element_t *list);

int main() {
  char filename[] = "numbers.txt";
  struct element_t *list = create_odd_list(filename);
  print_list(list);
  return 0;
}

struct element_t *create_odd_list(const char *filename) {
  struct element_t *first = NULL;
  struct element_t *last = NULL;

  FILE *fp = fopen(filename, "r");

  if (fp == NULL) {
    printf("Errore nell'apertura del file: %s\n", filename);
    exit(1);
  }
  
  int value;
  fscanf(fp, "%d", &value);

  while (!feof(fp)) {
    if (value % 2 != 0) {
      struct element_t *new = (struct element_t *) malloc(sizeof(struct element_t));
      
      if (new) {
	new -> value = value;
	new -> next = NULL;

	if (last == NULL)
	  first = last = new;
	else
	  last = last -> next = new;
      }
    }

    fscanf(fp, "%d", &value);
  }

  fclose(fp);

  return first;
}

void print_list(struct element_t *list) {
  for (struct element_t *current = list; current != NULL; current = current -> next)
    printf("%i ", current->value);

  printf("\n");
}
