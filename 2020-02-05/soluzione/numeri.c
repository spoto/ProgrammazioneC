#include <stdio.h>
#include <stdlib.h>

void scriviInFile (char nomeFile[])
{ 
    const float TERMINATORE =  0.0;
    FILE *fileDiTesto;
    float numero;
    
    fileDiTesto = fopen (nomeFile, "w");
	if (fileDiTesto == NULL)
	{
		printf("Errore!");
		exit(1);
	}
    printf ("Numero: ");
    scanf ("%f", &numero); 
    while(numero != TERMINATORE)
    {
      fprintf (fileDiTesto, "%.2f\n", numero);
      printf ("Numero: ");
      scanf ("%f", &numero);
     }
    fclose (fileDiTesto);
  } 


void leggiDaFile (char nomeFile[])
{
      FILE *fileDiTesto;
      float numero;
      fileDiTesto = fopen (nomeFile, "r");
	  if (fileDiTesto == NULL)
	  {
		  printf("Errore!");
		  exit(1);
	  }
      fscanf (fileDiTesto, "%f", &numero);
      while(!feof(fileDiTesto))
      { 
          printf ("Numero: %.2f\n", numero);
          fscanf (fileDiTesto, "%f", &numero);
      } 
     fclose (fileDiTesto);
}                         

void main()
{    char nomeArchivio[20]; 
	 printf("Nome file: ");
	 scanf("%s", &nomeArchivio);
     scriviInFile (nomeArchivio);
     leggiDaFile (nomeArchivio);
}