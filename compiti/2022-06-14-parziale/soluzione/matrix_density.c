#include <stdio.h>

#define SIZE 3

int is_dense(int matrix[][SIZE], int rows);
void print_matrix(int matrix[][SIZE], int rows);

/**
 * Entry point
 */
int main() {
    int matrix1[SIZE][SIZE] = {{0, 2, 0}, {1, 0, 0}, {4, 0, 8}};
    int matrix2[SIZE][SIZE] = {{0, 2, 0}, {4, 0, 6}, {0, 8, 9}};

    print_matrix(matrix1, SIZE);
    printf("Matrice densa? %i\n---\n", is_dense(matrix1, SIZE));

    print_matrix(matrix2, SIZE);
    printf("Matrice densa? %i\n---\n", is_dense(matrix2, SIZE));

    return 0;
}

/*
 * Ritorna 1 se il numero degli elementi diversi da zero della matrice specificata
 * è maggiore di quelli uguali da 0. Ritorna 0 in caso contrario.
 */
int is_dense(int matrix[][SIZE], int rows) {
    unsigned int row, col;
    int count = 0;

    for (row = 0; row < rows; row++) {
        for (col = 0; col < SIZE; col++) {
            if (matrix[row][col] != 0) {
                count++;
            }
        }
    }

    return count > (rows * SIZE) / 2;
}

/*
 * Stampa la matrice specificata.
 */
void print_matrix(int matrix[][SIZE], int rows) {
    unsigned int row, col;

    for (row = 0; row < rows; row++) {
        for (col = 0; col < SIZE; col++) {
            printf("%i ", matrix[row][col]);
        }
        printf("\n");
    }
}
