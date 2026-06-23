/*
   Completare il programma in modo che, dato un file di testo il cui nome
   viene inserito da tastiera, si contino e si stampino a video quante
   coppie sono ben formate.

   Il file contiene un numero indefinito di righe. Ogni riga contiene
   sicuramente due numeri interi positivi, num e m, con m sicuramente
   compreso tra 1 e 9.

   Una coppia num m si dice ben formata se il numero num contiene
   esattamente m cifre uguali a m.

   Ad esempio:

   * 1232 2 è ben formata, perché il numero 1232 contiene esattamente
     due cifre uguali a 2;
   * 121 1 non è ben formata, perché il numero 121 contiene due cifre
     uguali a 1, non una sola.

   In particolare, si completino le seguenti funzioni:

   int processafile(char *nome), che riceve il nome del file da processare,
   richiama la funzione contacifre e ritorna il numero di
   coppie ben formate e -1 in caso di errore.

   int contacifre(int num, int m), che conta quante cifre pari a m contiene num
   e che deve essere ricorsiva.
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
        if (contacifre(num, m) == m) {
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
