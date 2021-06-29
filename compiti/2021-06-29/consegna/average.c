// inizializza arr , lungo length , con numeri interi casuali
// tra -40 e 50 inclusi
void init_random ( int arr [] , int length ) {
  // DA COMPLETARE
}

// stampa su un ’ unica riga il contenuto dell ’ array arr ,
// lungo length , poi va a capo
void print_int ( int arr [] , int length ) {
  // DA COMPLETARE
}

// come sopra , ma stampa tre cifre decimali dopo la virgola
void print_double ( double arr [] , int length ) {
  // DA COMPLETARE
}

// considera l ’ array arr diviso in blocchi consecutivi di step elementi
// e calcola per ciascun blocco la media dei suoi step elementi ,
// scrivendola dentro result ; quindi ogni elemento di result
// e ’ la media di tre elementi consecutivi di arr
//
// e ’ sempre vero che arr ha lunghezza length
// e ’ sempre vero che ( la lunghezza di result ) * step == length
// e ’ sempre vero che step > 0
void average ( int arr [] , int length , int step , double result []) {
  // DA COMPLETARE
}

int main ( void ) {
  int arr [33];
  double result [11];
  init_random ( arr , 33) ;
  print_int ( arr , 33) ;
  // calcolo la media degli elementi di arr a gruppi di 3;
  // result ha infatti 11 elementi
  average ( arr , 33 , 3 , result ) ;
  print_double ( result , 11) ;
  return 0;
}
