#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
 {

   char password[20] ; /* la password inserita */
   char newpassword[20] ; /* la password modificata */
   int lung_stringa ; /* lunghezza della stringa inserita */
   int i ; /* indice dei cicli */
  
  /* LEGGI LA PASSWORD INSERITA DA TASTIERA */
  printf ("Inserisci una frase di al massimo %d caratteri: ", 20) ;
  fgets(password, 20, stdin) ;
  
  /* CALCOLA LA LUNGHEZZA DELLA PASSWORD */
  lung_stringa = strlen(password) ;
  
  /* STAMPA LA PASSWORD INSERITA */
  printf("La password inserita e': ");
  puts(password) ;
 

for ( i=0; i<lung_stringa; i=i+1 )
  {
  if ( password[i] == 'a')
  newpassword[i] ='@';
  else if( password[i] == 's')
  newpassword[i] ='$' ;
 else 
  newpassword[i]= password[i];
  }
 newpassword[lung_stringa] = '\0' ;
  
  /* STAMPA LA FRASE MODIFICATA */
  printf("La password modificata e' \n");
  puts(newpassword) ;
return 0;

 }
