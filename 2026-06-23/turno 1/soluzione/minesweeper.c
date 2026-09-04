/*
  Minesweeper è un gioco in cui l'utente deve trovare le mine utilizzando
  suggerimenti numerici che indicano quante mine sono direttamente adiacenti
  a una casella, orizzontalmente, verticalmente o diagonalmente.

  Si consideri una matrice di interi di dimensione 4x5. Ogni cella
  contiene -1 se contiene una mina, 0 se è vuota.
  Per ogni cella vuota (contenente 0), il programma deve calcolare
  il numero di mine presenti nelle celle adiacenti (orizzontali, verticali
  e diagonali). Se il numero di mine adiacenti è maggiore di 0,
  tale numero deve sostituire lo 0 nella cella.
  Se non vi sono mine adiacenti, la cella deve rimanere pari a 0.
  Le celle contenenti una mina (-1) non devono essere modificate.

  Si stampi infine la matrice ottenuta.
*/

#include <stdio.h>

#define NR 4
#define NC 5

int main() {

    int mappa[NR][NC];
    int i, j, r, c;
    int conta;

    /* lettura */
    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* aggiornamento */
    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++) {

            if(mappa[i][j] == 0) {

                conta = 0;

                for(r=i-1; r<=i+1; r++) {
                    for(c=j-1; c<=j+1; c++) {

                        if(r>=0 && r<NR && c>=0 && c<NC && !(r==i && c==j)) {

                            if(mappa[r][c] == -1)
                                conta++;
                        }
                    }
                }

                if(conta > 0)
                    mappa[i][j] = conta;
            }
        }
    }
	
	printf("Mappa aggiornata:\n");
    
    /* stampa */
    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++) {
            printf("%3d", mappa[i][j]);
        }
        printf("\n");
    }

    return 0;
}
