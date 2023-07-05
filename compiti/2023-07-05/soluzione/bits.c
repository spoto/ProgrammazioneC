#include <stdlib.h>
#include <time.h>

// riempie arr con interi casuali, divisibili per 3, tra 0 e 65535 inclusi;
// arr ha lunghezza length
void init_random(int arr[], int length) {
  srand(time(NULL));
  for (int pos = 0; pos < length; pos++)
    do {
      arr[pos] = rand() % 65536;
    }
    while (arr[pos] % 3 != 0);
}

// determina se n ha ripetizione due, cioe' se la sua rappresentazione
// binaria contiene almeno due bit ad 1 consecutivi;
// si dia per scontato che n sia tra 0 e 65535 inclusi;
// questa funzione deve essere ricorsiva
int ripetizione2(int n) {
  if (n < 2)
    return 0;
  else { // qui n >= 2
    int inizio = n / 2;
    return ripetizione2(inizio) || (n % 2 == 1 && inizio % 2 == 1);
  }
}

// fa una passata sull'array indicato scambiando
// due elementi consecutivi se non rispettano l'ordinamento
int swap(int array[], int length) {
  int ho_fatto_scambio = 0;
  for (int pos = 0; pos < length - 1; pos++)
    if (!ripetizione2(array[pos]) && ripetizione2(array[pos + 1])) {
      // scambia array[pos] con array[pos + 1]
      int temp = array[pos];
      array[pos] = array[pos + 1];
      array[pos + 1] = temp;
      ho_fatto_scambio = 1;
    }

  return ho_fatto_scambio;      
}

// ordina gli elementi di arr, lungo length, in modo da spostare all'inizio
// i suoi elementi che hanno ripetizione due e alla fine i suoi
// elementi che non hanno ripetizione due
void sort_by_ripetizione2(int arr[], int length) {
  while (swap(arr, length));  
}
