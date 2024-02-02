// inizializza l'array lungo length con numeri casuali tra 1 e 10 inclusi
void init_random(int arr[], int length) {
  // DA COMPLETARE
}

// stampa su una riga l'array lungo length e poi va a capo
void print(int arr[], int length) {
  // DA COMPLETARE
}

// modifica l'array arr, lungo length, in modo da mettere i suoi elementi distinti
// al suo inizio; ritorna il numero di tali elementi distinti.
//
// Per esempio, se arr fosse
//
// 4 6 4 6 2 3 7 6 9 10 5 8 2 9 5 4 9 4 5 6
//
// allora dopo la chiamata a questa funzione i nove elementi distinti di arr
// finirebbero al suo inizio, in qualsiasi ordine, seguiti da qualsiasi valore.
// Per esempio l'array potrebbe diventare
//
// 3 7 10 8 2 9 4 5 6 .................
//
// (non importa cosa contengano gli undici elementi finali)
// e la funzione ritornera' 9 (numero di elementi distinti)
int only_distinct(int arr[], int length) {
  // DA COMPLETARE
}

int main(void) {
  int arr[20];
  init_random(arr, 20);
  print(arr, 20); // stampa di arr prima di chiamare only_distinct()
  int x = only_distinct(arr, 20);
  print(arr, x); // stampa degli elementi distinti di arr
  return 0;
}
