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
*  legge un file identificato da FILE * f, distingue la singole equazioni grazie al ";" che ne determina la fine
*  restituisce la frazione di equazioni corrette sul totale
*/
int calcolaSomma(FILE* fp)
{
    int num, somma, singolovalore;
    char cifralettere[8];
    somma = 0;
    num=0;
    while (fscanf(fp,"%s",cifralettere) != EOF)
    {
      if (strcmp(cifralettere,"stop") ==0)
      {
          somma +=num;
          num = 0;
       }
       else
       {
           for(int i=0; i<10; i++)
           {
              if(strcmp(cifralettere,cifre[i].lettera) ==0)
              {
                      singolovalore=cifre[i].valore;
              }
           }
           num = num * 10 + singolovalore;
       }
  }
  return somma;
}
