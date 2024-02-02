#include <stdio.h>
#include<string.h>
#include<stdlib.h>

char* AggiungiSoprannome(char* nome_cognome, char* soprannome)
{
	char *ris; /* stringa risultato */
	int i; /* indice per scorrere il soprannome */
	int j; /* indice per scorrere il risultato */
	int k; /* indice per scorrere nome e cognome */
	int num_spazi = 0; /* numero di spazi tra nome e cognome */
	for (k = 0; nome_cognome[k] != '\0'; k++)
		if (nome_cognome[k] == ' ')
			num_spazi++;
		ris = (char*) malloc(strlen(nome_cognome) - num_spazi +strlen(soprannome) + 5);
      /* 5 caratteri extra: 2 parentesi, 2 spazi, 1 terminatore */
    for (k = 0; nome_cognome[k] != ' '; k++)
	     ris[k] = nome_cognome[k];
    j = k;
    ris[j++] = ' ';
	ris[j++] = '(';
	for (i = 0; soprannome[i] != '\0'; i++, j++)
			ris[j] = soprannome[i];
	ris[j++] = ')';
	ris[j++] = ' ';
	for ( ; nome_cognome[k] == ' '; k++)
		;
	for ( ; nome_cognome[k] != '\0'; k++, j++)
		ris[j] = nome_cognome[k];
	ris[j] = '\0';

	return ris;
}
void main()
{ 
	char stringa_nome[31], stringa_soprannome[21], ch;
	int i = 0;
	printf("Inserisci la stringa con nome e cognome\n");
	while ( (ch = getchar()) != '\n')
	stringa_nome[i++] = ch;
	stringa_nome[i] = '\0';
	i = 0;
	printf("Inserisci la stringa con il soprannome\n");
	while ( (ch = getchar()) != '\n')
	stringa_soprannome[i++] = ch;
	stringa_soprannome[i] = '\0';
	printf("%s\n",AggiungiSoprannome(stringa_nome, stringa_soprannome));
}