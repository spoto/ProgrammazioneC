#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX_RIGHE 100
#define MAX_COLONNE 200
#define SIZE 50

int myerror(char *message);
int myfclose(FILE *f);
FILE * myfopen(char *name, char *mode);
void leggimatrice(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[]);
int dimensioneMatriceRidotta(int matrice[MAX_RIGHE][MAX_COLONNE],int n);
void scriviInversaMatriceRidotta(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[],int n_ridotto);

int main()
{
    char filename[SIZE];
    printf("File: ");
    fgets(filename, SIZE - 1, stdin);
    filename[strlen(filename) - 1] = '\0';
    int matrice[MAX_RIGHE][MAX_COLONNE],n_ridotto;
    int dimensioni[2];
    leggimatrice(filename,matrice,dimensioni);
    int n = dimensioni[0];
    int m = dimensioni[1];
    n_ridotto=dimensioneMatriceRidotta(matrice,n);
    scriviInversaMatriceRidotta("out.txt",matrice,dimensioni,n_ridotto);
  return 0;
}

int myerror(char *message)
{
    fputs( message, stderr );
    exit(1);
}
/**
 *  chiude  lo stream su file controllando se ci sono errori,
 *  invoca myerror sia che f sia null sia che il risultato delle
 *  chiusura sia diverso da zero
 */
int myfclose(FILE *f)
{
   
}
/**
*  apre  lo stream su file controllando se ci sono errori,
*  invoca myerror se f è null
*/
FILE * myfopen(char *name, char *mode)
{
   
}
/**
*  legge un file indentificato da filename, popola una matrice e ne definisce le dimensioni
*  in un array in cui il numero delle righe è la prima componente ed il numero di  colonne la seconda
* fa uso di myfopen e myfclose
*/
void leggimatrice(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[])
{
   
}
/**
*  calcola il numeor di righe della matrice risultante, quella che non ha righe che iniiano con 0
*/
int dimensioneMatriceRidotta(int matrice[MAX_RIGHE][MAX_COLONNE],int n)
{
    
}
/**
*  scrive un file indentificato da filename, popolandolo con la versione a righe invertite della matrice
*  omettendo le righe che iniziano con 0
*  nella prima riga del file scrive il numero di righe e di colonne che ci si deve aspettare di trovare nel prosieguo
*/
void scriviInversaMatriceRidotta(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[],int n_ridotto)
{
   
}
