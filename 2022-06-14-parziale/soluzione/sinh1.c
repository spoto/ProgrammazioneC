#include <stdio.h> /* printf, NULL */

int f(int n);
double sinh1(int n);

int main() {
    printf("Valore di sinh1: %lf\n", sinh1(10));
    return 0;
}

/**
 * Restituisce il fattoriale di un numero n calcolato in modo ricorsivo
 */
int f(int n) {
    int i;
    int result = 1;

    for (i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

/**
 * Calcola la somma, preferibilmente in modo ricorsivo, dei primi n termini della serie sequente
 * che rappresenta lo sviluppo di Taylor-Mc Laurin del seno iperbolicoo
 */
double sinh1(int n) {
    int i;
    double result = 0;

    for (i = 0; i < n; i++) {
        result += (double)1 / f(2 * i + 1);
    }

    return result;
}

/**
 * Calcola la somma, preferibilmente in modo ricorsivo, dei primi n termini della serie sequente
 * che rappresenta lo sviluppo di Taylor-Mc Laurin del seno iperbolicoo
 */
double sinh2(int n) {
    if (n == 0) {
        // Caso base: se n è uguale a 0 restituisce 1/1
        return 1;
    } else {
        // Passo ricorsivo: ritorna l'n-esimo termine + sinh2(n-1)
        return ((float)1 / f(2 * n + 1)) + sinh2(n - 1);
    }
}
