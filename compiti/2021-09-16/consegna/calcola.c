#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myerror(char *message);
int myfclose(FILE *f);
FILE * myfopen(char *name, char *mode);
int calcolaSomma(FILE* fp);
struct cifra{char lettera[8]; int valore;};
struct cifra cifre[10] = { {"zero",0} , {"uno",1} , {"due",2} , {"tre",3} ,
                            {"quattro",4} , {"cinque", 5} , {"sei",6} ,
                            {"sette",7} , {"otto",8} , {"nove",9}
};

int main()
{
    char filename[6] = "in.txt";
    FILE* fp;
    fp = myfopen(filename,"r");
    int risultato = calcolaSomma(fp);
    myfclose(fp);
    printf("La somma  di tutti i numeri risulta: %d \n",risultato);
  return 0;
}

int myerror(char *message)
{
    // DA COMPLETARE
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
int calcolaSomma(FILE* fp)
{
    // DA COMPLETARE
}
