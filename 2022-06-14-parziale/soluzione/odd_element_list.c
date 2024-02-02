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
    struct element_t *current = NULL;
    struct element_t *prev = NULL;
    struct element_t *new = NULL;
    struct element_t *head = NULL;

    FILE *fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file: %s\n", filename);
        exit(1);
    }

    int value;
    fscanf(fp, "%d", &value);

    while (!feof(fp)) {
        if (value % 2 != 0) {
            new = (struct element_t *)malloc(sizeof(struct element_t));

            if (new) {
                if (head == NULL) {
                    head = new;
                    new->next = NULL;
                } else {
                    current = head;
                    prev = head;

                    while (current) {
                        prev = current;
                        current = current->next;
                    }

                    prev->next = new;
                }

                new->value = value;
            }
        }
        fscanf(fp, "%d", &value);
    }
    fclose(fp);
    return head;
}

void print_list(struct element_t *list) {
    struct element_t *current = list;

    while (current != NULL) {
        printf("%i ", current->value);
        current = current->next;
    }

    printf("\n");
}
