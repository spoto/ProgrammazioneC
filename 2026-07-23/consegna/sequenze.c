/*
Completare il programma definendo i seguenti sottoprogrammi:

il sottoprogramma RICORSIVO contaseq che prende in input una stringa e restituisce la lunghezza della sequenza iniziale di caratteri alfabeticamente consecutivi in ordine crescente. Una sequenza è strettamente crescente se ogni carattere è il successivo di quello nella posizione precedente, secondo l'ordine alfabetico (ad esempio, 'b' segue 'a', 'c' segue 'b', ecc.).
il sottoprogramma conta che prende in input una stringa (nome di file) e un intero soglia, apre il file con nome corrispondente al primo parametro e restituisce quante sono le parole nel file la cui sequenza iniziale di caratteri in ordine alfabetico strettamente crescente ha lunghezza maggiore della soglia (determinata invocando il sottoprogramma contaseq per ogni parola letta dal file).

Ciascuna parola presente nel file di origine è composta da al più 25 caratteri. Ogni riga del file contiene una parola. Nel caso in cui si verifichino problemi di accesso al file, il sottoprogramma restituisce -1.

Per esempio, se nel file sono presenti le parole

abcde
abca
abdc
xyz
aacd

e la soglia vale 3, il programma stampa a video 1.

Infatti:

abcde  -> sequenza iniziale crescente "abcde" (lunghezza 5)
abca   -> sequenza iniziale crescente "abc"   (lunghezza 3)
abdc   -> sequenza iniziale crescente "ab"    (lunghezza 2)
xyz    -> sequenza iniziale crescente "xyz"   (lunghezza 3)
aacd   -> sequenza iniziale crescente "a"     (lunghezza 1)

Solo "abcde" ha una sequenza iniziale crescente di lunghezza maggiore di 3.
Se invece la soglia fosse pari a 2, le parole corrette sarebbero "abcde", "abca" e "xyz".
*/

#include<stdio.h>
#include<string.h>
#define DIM 25

/*prototipi delle funzioni*/
int contaseq(char *);
int conta(char *, int);

int main(){
	char nome[100];
	int soglia;
	int num;
	
	scanf("%s",nome);
	scanf("%d",&soglia);
	num=conta(nome, soglia);
	printf("%d\n",num);
	return 0;

}

// funzione ricorsiva
int contaseq(char *s) {
    
}


int conta(char *nome, int soglia){
	

}
