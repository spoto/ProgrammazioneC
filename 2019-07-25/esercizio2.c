#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct elem
{
  char abbr[2];
  char *estesa;
  struct elem *next;
};

int cerca(struct elem *l, char a[2], char *p)
{
  int app;
   while ( l->next && (l->abbr[0] != a[0] || l->abbr[1] != a[1]) )
     l = l->next;
/* si esce dal ciclo perche’ siamo sull’ ultimo record (CASO A)
o sul record che contiene l’abbreviazione (CASO B)
o entrambe le cose contemporaneamente (CASO C) */
    if ( (l->abbr[0] == a[0]) && (l->abbr[1] == a[1]) )
     if ( strcmp(l->estesa, p) !=0 )
	  {/* Caso B o C. La parola estesa e’ differente: la sostituisco */
		l->estesa = (char * ) realloc(l->estesa, strlen(p)+1);
		strcpy(l->estesa, p);
		app = 2; /* abbreviazione esistente parola estesa differente */
    }
	else app = 0; /* Caso B o C. La parola estesa e’ OK */
 else
	{ /* Caso A: siamo sull’ultimo record che NON contiene l’abbreviazione
			aggiungo un record in coda alla lista */
     l->next = (struct elem *)malloc(sizeof(struct elem));
     l = l->next;
     l->estesa = (char *) malloc(strlen(p)+1);
     strcpy(l->estesa, p);
     l->abbr[0] = a[0];
     l->abbr[1] = a[1];
     l->next = 0,
     app = 1; /* abbreviazione non esistente */
    }
   return app;
 }
void stampa(struct elem * l)
{ /* stampa la lista, non richiesta */
  while (l != NULL){
  printf("%c%c %s \n",l->abbr[0],l->abbr[1],l->estesa);
  l = l->next;
  }
}
struct elem *crealista(int k) /* funzione di appoggio, non richiesta */
{ /* crea una lista di k elementi */
   int i;
   struct elem *l, *app;
   char c[21];
   if(k == 0)
    return NULL;
   else
     {
      app = l = (struct elem *) malloc(sizeof(struct elem)); /* record generatore */
      for(i = 0;i < k;++i)
       {
         l->next = (struct elem *)malloc(sizeof(struct elem));
         l = l->next;
         printf("Abbreviazione : ");
         scanf("%c%c",&(l->abbr[0]), &(l->abbr[1]));
         printf("Estesa : ");
         scanf("%s%*c",c); /* %*c consuma il \n */
         l->estesa = (char *) malloc(strlen(c)+1);
         strcpy(l->estesa,c);
      }
      l->next = NULL;
      l = app->next;
      free (app);
      return l;
   }
 }
int main (void) 
{
    struct elem *p1, **v;
    int i, termina;
    char app[2] = {'z','z'},str[21];
    p1 = crealista(3); /*crea una lista di 3 elementi */
    stampa(p1);   
	 printf("inserire xx per uscire dal ciclo di controllo...\n");
    while ((app[0] != 'x') || (app[1] != 'x') )
    {
      printf ("Abbreviazione : ");
      scanf("%c%c",&app[0],&app[1]);
	  if ((app[0] != 'x') || (app[1] != 'x')){
      printf("Estesa : ");
      scanf("%s%*c",str);
      printf("%c%c %s : %d \n",app[0],app[1],str,cerca(p1,app,str));
	 }
   }
    stampa(p1);
   }
    