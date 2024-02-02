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
}

void print_list(struct element_t *list) {
}
