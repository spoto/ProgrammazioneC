// aggiungete gli #include necessari

struct List *create(int head, struct List *tail) {
  // ritorna una nuova lista con la testa e la coda indicate
}

void print(struct List *this) {
  // stampa gli elementi di this, dal primo all'ultimo, su una
  // riga, separati da spazi, andando a capo alla fine;
  // si noti che this potrebbe essere NULL
}

struct List *from(int arr[], int length) {
  // ritorna una lista contenente esattamente gli elementi
  // di arr, lungo length, nell'ordine in cui sono presenti
  // nell'array; se length fosse 0, dovra' ritornare NULL
}

struct List *filter(struct List *this, int threshold) {
  // ritorna una lista contenente i soli elementi di this
  // che sono maggiori o uguali a threshold;
  // si noti che this puo' essere NULL e che il risultato
  // sara' NULL se non ci fossero elementi maggiori o uguali
  // a threshold
  
  // QUESTA FUNZIONE DEVE ESSERE RICORSIVA
}

struct List *duplicate(struct List *this) {
  // ritorna una lista identica a this ma con gli elementi
  // duplicati; per esempio, se this fosse la lista 1 2 3, allora
  // questa funzione deve ritornare la lista 1 1 2 2 3 3;
  // si noti che this puo' essere NULL e che il risultato sara'
  // NULL se this fosse vuota

  // QUESTA FUNZIONE DEVE ESSERE RICORSIVA
}
