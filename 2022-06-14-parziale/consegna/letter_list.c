#include <stdio.h>
#include <stdlib.h>

#define NUM_OF_LETTERS 3

struct letter_t {
    char ch;
    int count;
    struct letter_t *next;
};

struct letter_t *new_letter(char ch);
struct letter_t *insert_letter_in_tail(struct letter_t *head, char ch);
int count_letter(struct letter_t *head, char ch);
void print_list(struct letter_t *head);

int main() {
    int n = 10;
    struct letter_t *head = NULL;

    srand(0);

    for (int i = 0; i < n; i++) {
        char ch = 'A' + rand() % NUM_OF_LETTERS;
        head = insert_letter_in_tail(head, ch);
    }

    print_list(head);
    printf("Occorrenze di A: %d\n", count_letter(head, 'A'));
    return 0;
}

struct letter_t *new_letter(char ch) {
}

struct letter_t *insert_letter_in_tail(struct letter_t *head, char ch) {
}

void print_list(struct letter_t *head) {
}

int count_letter(struct letter_t *head, char ch) {
}
