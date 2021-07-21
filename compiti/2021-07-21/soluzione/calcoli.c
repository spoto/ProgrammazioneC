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
float calcola(FILE* fp)
{
    int num, sin_val = 0, des_val = 0, equazioni = 0, equazioni_corrette = 0;
    int parte_sin = 1;
    char ch;
    while (fscanf(fp,"%d%c",&num,&ch) != EOF)
    {
      if (ch == '+')
      {
       	 if (parte_sin) /* siamo nella parte sinistra */
          {
          	sin_val += num;
	  }
        	  else
        	  {
          	des_val += num;
           }
      }
      else 
      {	
      	if (ch == '=')
      	{
          sin_val += num;
          parte_sin = 0;
      	}
      	else /* ch == ';' */
        {
          des_val += num;
          equazioni++;
          if (sin_val == des_val)
          {
            equazioni_corrette++;
           }   
          sin_val = 0;
          des_val = 0;
          parte_sin = 1;
        }
        //printf("equazioni_corrette  %d equazioni %d \n", equazioni_corrette, equazioni);
      }  
  }
  return (float) equazioni_corrette/equazioni; 
}
