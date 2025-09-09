// SI AGGIUNGANO #include SE SERVONO

// crea una struttura sentence che contiene le parole fornite,
// nell'ordine in cui sono presenti nell'array;
// tali parole non vanno duplicate: se ne deve solo copiare
// il puntatore dentro la struttura risultante;
// length e' la lunghezza dell'array words
struct sentence *construct_sentence(char *words[], int length) {
  // COMPLETARE
}

// dealloca una struttura s precedentemente allocata con construct_sentence():
// deve deallocare tutta la lista, non solo il suo primo elemento
void free_sentence(struct sentence *s) {
  // COMPLETARE
}

// ritorna la lunghezza di s, cioe' la somma delle lunghezze delle parole di s,
// considerando anche uno spazio tra una parola e l'altra
int length_sentence(struct sentence *s) {
  // COMPLETARE
}

// concatena le parole di s dentro result, con uno spazio tra una parola
// e l'altra; si assuma che result sia sufficientemente grande da contenere
// il risultato della concatenazione; questa funzione deve essere ricorsiva
void concat_sentence_rec(struct sentence *s, char *result) {
  // COMPLETARE
}

// ritorna una nuova stringa che contiene la concatenazione
// delle parole di s, con uno spazio tra una parola e l'altra
char *concat_sentence(struct sentence *s) {
  // COMPLETARE
}

// concatena le parole di s dentro result, con uno spazio tra una parola
// e l'altra, in ordine inverso (prima l'ultima parola, alla fine la prima parola);
// si assuma che result sia sufficientemente grande da contenere
// il risultato della concatenazione; questa funzione deve essere ricorsiva;
// questa funzione ritorna il puntatore alla fine della stringa
// risutante, dove si trova lo \0 finale
char *inverse_concat_sentence_rec(struct sentence *s, char *result) {
  // COMPLETARE
}

// ritorna una nuova stringa che contiene la concatenazione delle parole di s,
// con uno spazio tra una parola e l'altra, in ordine inverso
// (prima l'ultima parola, alla fine la prima parola)
char *inverse_concat_sentence(struct sentence *s) {
  // COMPLETARE
}
