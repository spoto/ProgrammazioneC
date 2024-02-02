#ifndef HARSHAD_H
#define HARSHAD_H

// inizializza arr, lungo length, con numeri interi casuali tra 0 a 999,
// usando srand() e rand(), facendo in modo che alla fine
// non ci siano elementi consecutivi uguali nell'array
void init_random(long arr[], int length);

// stampa su un'unica riga il contenuto dell'array arr, lungo length, poi va a capo
void print(long arr[], int length);

// determina se n e' un numero Harshad, cioe' e' positivo e divisibile per la
// somma delle proprie cifre. Per esempio, 1729 e' Harshad
// poiche' 1+7+2+9 fa 19 e 1729 e' divisibile per 19
int is_harshad(long n);

// modifica l'array, lungo length, in modo da riempirlo con i primi
// length numeri Harshad
void fill_with_harshad(long arr[], int length);

#endif
