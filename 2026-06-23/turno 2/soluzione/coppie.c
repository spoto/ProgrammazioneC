/*
  Completare il programma in modo che, dato un file di testo il cui nome
  viene inserito da tastiera, conti e stampi a video quante coppie sono
  fortunate.

  Il file contiene un numero indefinito di righe. Ogni riga contiene
  sicuramente due numeri interi positivi, num e m, con m sicuramente
  compreso tra 1 e 9.

  Una coppia num m si dice fortunata se la cifra m compare un numero
  di volte pari.

  Esempi:

  1232 2 è fortunata;
  121 1 è fortunata;
  12345 3 non è fortunata.

  In particolare, completare le seguenti funzioni:

  int processafile(char *nome), che riceve il nome del file da processare,
  richiama la funzione contacifre e ritorna il numero di coppie ben formate,
  o -1 in caso di errore;

  int contacifre(int num, int m), che deve essere ricorsiva e che conta
  quante cifre pari a m contiene num.
*/

#include <stdio.h>

int processafile(char *nome);
int contacifre(int num, int m);

int main() {
    char nomefile[50];
    int risultato;

    scanf("%s", nomefile);
    risultato = processafile(nomefile);

    if (risultato == -1) {
        printf("Errore nell'apertura del file.\n");
    } else {
        printf("Numero coppie fortunate: %d\n", risultato);
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
        if (contacifre(num, m) % 2 == 0) {
            count++;
        }
			 fscanf(fp, "%d %d", &num, &m);
    }

    fclose(fp);

    return count;
}

int contacifre(int num, int m) {
    if (num == 0) {
        return 0;
    }

    if (num % 10 == m) {
        return 1 + contacifre(num / 10, m);
    } else {
        return contacifre(num / 10, m);
    }
}
