#include <stdio.h>

#define N 4

int main(void) {
    int A[N][N];
    int i, j, k;
    int r, c;
    int somma, conta;
    int cifreCentro, cifreElemento;
    int valore;
    int dominante;


    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    for (k = 0; k < N; k++) {
        somma = 0;
        conta = 0;
        dominante = 1;

        // calcolo del numero di cifre
        valore = A[k][k];
        cifreCentro = 0;
        do {
            cifreCentro++;
            valore = valore / 10;
        } while (valore > 0);

        // Scorro la finestra 3 x 3 centrata in A[k][k].
        for (r = k - 1; r <= k + 1; r++) {
            for (c = k - 1; c <= k + 1; c++) {
                // verifico se la posizione è valida
                if (r >= 0 && r < N && c >= 0 && c < N) {

                    // escludo l'elmento centrale e gli elementi sulla diagonale
                    if (!(r == k && c == k) && r != c) {
                        somma += A[r][c];
                        conta++;

                        // numero di cifre
                        valore = A[r][c];
                        cifreElemento = 0;
                        do {
                            cifreElemento++;
                            valore = valore / 10;
                        } while (valore > 0);

                        /*
                           Se almeno un elemento dell'intorno ha un numero
                           di cifre maggiore o uguale a quello del centro,
                           A[k][k] non puo' essere dominante.
                        */
                        if (cifreElemento >= cifreCentro) {
                            dominante = 0;
                        }
                    }
                }
            }
        }

        // condizione sulla media
        if (!(A[k][k] * conta > somma)) {
            dominante = 0;
        }

        if (dominante) {
            printf("%d ", k);
        }
    }

    return 0;
}
