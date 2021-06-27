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
    int ris;
    if (f==NULL)
    {
        myerror("ERRORE INTERNO\n");
    }
    ris = fclose(f);
    if( ris!=0 )
    {
        myerror("Impossibile chiudere\n");
    }
    return ris;
}
/**
*  apre  lo stream su file controllando se ci sono errori,
*  invoca myerror se f è null
*/
FILE * myfopen(char *name, char *mode)
{
    FILE * f;
    f = fopen( name, mode );
    if (f==NULL)
    {
        printf("Impossibile aprire %s\n", name);
        exit(1) ;
    }
    return f;
}
/**
*  legge un file indentificato da filename, popola una matrice e ne definisce le dimensioni
*  in un array in cui il numero delle righe è la prima componente ed il numero di  colonne la seconda
*/
void leggimatrice(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[])
{
    FILE* fp;
    int i, j,n,m;
    fp = myfopen(filename,"r");
    fscanf(fp,"%dX%d",&n,&m);
    dim[0] = n;
    dim[1] = m;
    for (i = 0; i < n; i++)
    {
      for (j = 0; j < m; j++)
      {
          fscanf(fp, "%d", &matrice[i][j]);
      }
    }
    myfclose(fp);
}

int dimensioneMatriceRidotta(int matrice[MAX_RIGHE][MAX_COLONNE],int n)
{
  int n_ridotto = n;
  int i;
  for (i = 0; i < n; i++)
  {
      if (matrice[i][0] == 0)
      {
          n_ridotto--;
      }
  }
    return n_ridotto;
}

void scriviInversaMatriceRidotta(char filename[], int matrice[MAX_RIGHE][MAX_COLONNE],int dim[],int n_ridotto)
{
    FILE* fp;
    int i, j;
    int n = dim[0];
    int m = dim[1];
    fp = myfopen(filename,"w");
    fprintf(fp, "%dX%d\n", n_ridotto, m);
    for (i = n-1; i >= 0; i--)
    {
      if (matrice[i][0] != 0)
      {
          for (j = 0; j < m; j++)
          {
             fprintf(fp, "%3d ",matrice[i][j]);
          }
          fprintf(fp, "\n");
      }
  }
  myfclose(fp);
}
