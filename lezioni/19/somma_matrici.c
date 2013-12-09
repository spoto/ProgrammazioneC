// somma due matrici 4x3

#include <stdio.h>

int main(void) {
  const float matrice1[4][3] = {
    { 1.2, 3.4, -0.6 },
    { 0.0, 0.1, 8.11 },
    { 1.8, -2.9, -0.2 },
    { 0.0, 0.0, 11.9 }
  };

  float matrice2[4][3];

  float risultato[4][3];

  int riga, colonna;

  // leggo da tastiera la seconda matrice
  for (riga = 0; riga < 4; riga++)
    for (colonna = 0; colonna < 3; colonna++) {
      printf("matrice[%i][%i]: ", riga, colonna);
      scanf("%f", &matrice2[riga][colonna]);
    }
 
  // calcolo il risultato
  for (riga = 0; riga < 4; riga++)
    for (colonna = 0; colonna < 3; colonna++)
      risultato[riga][colonna] = matrice1[riga][colonna] + matrice2[riga][colonna];

  // stampiamo il risultato
  for (riga = 0; riga < 4; riga++) {
    for (colonna = 0; colonna < 3; colonna++)
      printf("%8.2f", risultato[riga][colonna]);

    printf("\n");
  }

  return 0;
}
