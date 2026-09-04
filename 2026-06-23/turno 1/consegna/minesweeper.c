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
    int i, j;

    /* lettura */
    for(i=0; i<NR; i++) {
        for(j=0; j<NC; j++) {
            scanf("%d", &mappa[i][j]);
        }
    }

    /* aggiornamento */
    
    
	
	printf("Mappa aggiornata:\n");
    
    /* stampa */
    

    return 0;
}
