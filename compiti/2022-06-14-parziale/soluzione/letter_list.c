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
    struct letter_t *new = (struct letter_t *)malloc(sizeof(struct letter_t));

    if (new == NULL) {
        printf("Errore nell'allocazione della memoria\n");
        exit(1);
    }
    new->ch = ch;
    new->count = 0;
    new->next = NULL;
    return new;
}

struct letter_t *insert_letter_in_tail(struct letter_t *head, char ch) {
    struct letter_t *new = new_letter(ch);
    struct letter_t *current = head;

    if (head == NULL) {
        head = new;
    } else {
        while (current->next) {
            current = current->next;
        }
        current->next = new;
    }
    return head;
}

void print_list(struct letter_t *head) {
    struct letter_t *current = head;

    while (current) {
        printf("%c ", current->ch);
        current = current->next;
    }
    printf("\n");
}

int count_letter(struct letter_t *head, char ch) {
    int count = 0;
    struct letter_t *current = head;

    while (current) {
        if (current->ch == ch) {
            count++;
        }
        current = current->next;
    }
    return count;
}
