/*
  Completare il programma in modo che, dato un file di testo il cui nome
  viene inserito da tastiera, si contino e si stampino a video quante
  coppie sono ben formate.

  Il file contiene un numero indefinito di righe. Ogni riga contiene
  sicuramente due numeri interi strettamente positivi, num e m,
  con m sicuramente compreso tra 1 e 9.

  Una coppia num m si dice ben formata se il numero num contiene
  esattamente m cifre.

  Ad esempio:
  * 1232 2 non è ben formata, perché il numero 1232 non è composto da 2 cifre;
  * 121 3 è ben formata, perché il numero 121 contiene 3 cifre.

  In particolare, completare le seguenti funzioni:

  int processafile( char * nome ) che riceve il nome del file da processare,
  richiama le altre funzioni elencate di seguito e ritorna il numero di
  coppie ben formate e -1 in caso di errore.
  int benformata(int num, int m) è una funzione ricorsiva,
  che restituisce 1 se la coppia è ben formata, 0 altrimenti.
*/

#include <stdio.h>

int processafile(char *nome);
int benformata(int num, int m);

int main() {
    char nomefile[50];
    int risultato;

    scanf("%s", nomefile);
    risultato = processafile(nomefile);

    if (risultato == -1) {
        printf("Errore nell'apertura del file.\n");
    } else {
        printf("Numero coppie ben formate: %d\n", risultato);
    }

    return 0;
}

int processafile(char *nome) {
    FILE *fp;
    int num;
    int m;
    int count =0;

    fp = fopen(nome, "r");

    if (fp == NULL) {
        return -1;
		}
    fscanf(fp, "%d %d", &num, &m);
		while (!feof(fp)) {
        if (benformata(num, m)) {
            count++;
        }
			 fscanf(fp, "%d %d", &num, &m);
    }

    fclose(fp);

    return count;
}

int benformata(int num, int m) {
    if (num == 0 && m == 0)
        return 1;

    if (num == 0 || m == 0)
        return 0;

    return benformata(num / 10, m - 1);
}
