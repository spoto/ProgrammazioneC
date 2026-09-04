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
    int i, j;

    /* lettura */
    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* aggiornamento */
    
    
	
	
    /* stampa massimo e coordinate*/
    

    return 0;
}
