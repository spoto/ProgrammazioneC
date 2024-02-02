#include <stdio.h>
#include <stdlib.h>

double calcola(double a, int n);
int main()
{
     int a,n;
     printf("Inserisci un numero tra 1 e 20\n");
     scanf("%d", &a);
     printf("Inserisci un numero tra 1 e 20\n");
     scanf("%d", &n);
    double risultato = calcola(a,n);
    printf("Il risultao : %f\n",risultato);
  return 0;
}

double calcola(double a, int n)
{
    double result;
    if (n==1)
    {
        result = (a - 1/a);
        return result;
    }
    else
    {
        result = a - n/a + calcola(a, n-1);
        return result;
    }
}
