#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myerror(char *message);
int myfclose(FILE *f);
FILE * myfopen(char *name, char *mode);
float calcola(FILE* fp);

int main()
{
    char filename[6] = "in.txt";
    FILE* fp;
    fp = myfopen(filename,"r");
    float risultato = calcola(fp);
    myfclose(fp);
    printf("Le equazioni corrette sono il %.2f %% \n",(risultato*100));
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
  // DA COMPLETARE
}
/**
*  apre  lo stream su file controllando se ci sono errori,
*  invoca myerror se f è null
*/
FILE * myfopen(char *name, char *mode)
{
  // DA COMPLETARE
}
/**
*  legge un file identificato da FILE * f, distingue la singole equazioni grazie al ";" che ne determina la fine
*  restituisce la frazione di equazioni corrette sul totale
*/
float calcola(FILE* fp)
{
    int parte_sin = 1;
    // DA COMPLETARE
}
