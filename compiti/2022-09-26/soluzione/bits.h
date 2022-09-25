// riempie arr con interi casuali tra 0 e 65535 inclusi;
// arr ha lunghezza length
void init_random(int arr[], int length);

// ritorna la popolazione di n, cioe' il numero di bit ad 1
// nella rappresentazione binaria di n. Si dia per scontato
// che n sia tra 0 e 65535 inclusi
int population(int n);

// ordina gli elementi di arr in ordine non decrescente per popolazione;
// arr ha lunghezza length
void sort_by_population(int arr[], int length);
