/*
  Una rete di monitoraggio è rappresentata da una matrice di interi
  di dimensione 4×5. Ogni cella della matrice può contenere:

  -1 se il sensore è guasto;
  0 se il sensore è funzionante.

  Per ogni sensore funzionante (cioè per ogni cella contenente 0),
  il programma deve calcolare il numero di sensori guasti presenti
  nelle celle adiacenti, considerando le otto direzioni possibili:
  orizzontale, verticale e diagonale.

  Se il numero di sensori guasti adiacenti è maggiore di 0,
  tale numero deve sostituire lo 0 presente nella cella.

  Se non vi sono sensori guasti adiacenti, la cella deve rimanere pari a 0.
  Le celle contenenti un sensore guasto (-1) non devono essere modificate.

  Terminato l'aggiornamento della matrice, il programma deve individuare
  la cella non guasta che contiene il numero massimo di sensori guasti
  adiacenti. Infine, deve stampare:

  - il valore massimo individuato;
  - le coordinate (riga, colonna) della cella che contiene tale valore.

  Nel caso in cui più celle contengano lo stesso valore massimo,
  il programma deve stampare le coordinate della prima cella incontrata
  durante la scansione della matrice per righe, da sinistra a destra
  e dall'alto verso il basso.
*/

#include <stdio.h>
#define NR 4
#define NC 5

int main() {
    int mappa[NR][NC];
    int i, j, r, c;
    int conta;
    int massimo = -1;
    int rigaMax = 0, colonnaMax = 0;

    /* lettura */
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* aggiornamento */
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {

            if (mappa[i][j] == 0) {
                conta = 0;

                for (r = i - 1; r <= i + 1; r++) {
                    for (c = j - 1; c <= j + 1; c++) {

                        if (r >= 0 && r < NR &&
                            c >= 0 && c < NC &&
                            !(r == i && c == j)) {

                            if (mappa[r][c] == -1) {
                                conta++;
                            }
                        }
                    }
                }

                mappa[i][j] = conta;
            }
        }
    }

    /* ricerca massimo tra le celle non guaste */
    for (i = 0; i < NR; i++) {
        for (j = 0; j < NC; j++) {
            if (mappa[i][j] != -1 && mappa[i][j] > massimo) {
                massimo = mappa[i][j];
                rigaMax = i;
                colonnaMax = j;
            }
        }
    }

    printf("Massimo: %d\n", massimo);
    printf("Coordinate: %d %d\n", rigaMax, colonnaMax);

    return 0;
}
