
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 10 // Numero di gare
#define M 20 // Lunghezza massima stringa Nome/Cognome


typedef struct pilota {
    char nome[M];
    char cognome[M];
    int posizioniGare[N];
    int punteggioTotale;
    struct pilota* next;
} Pilota;


int CalcolaPunteggio(int const * posizioni, int const * tabella){
    int punteggio = 0;
    for (int i = 0; i < N; i++) {
        if (posizioni[i] > 0 && posizioni[i] <= 15) {
            punteggio += tabella[posizioni[i] - 1];
        }
    }
    return punteggio;
}

Pilota* NuovoPilota(char* nome, char* cognome, int* posizioni) {
    Pilota* nuovopilota = (Pilota*)malloc(sizeof(Pilota));
    if (nuovopilota == NULL) {
        printf("Errore nell'allocazione di memoria per un nuovo pilota");
        exit(1);
    }
    strncpy(nuovopilota->nome, nome, M - 1);
    nuovopilota->nome[M - 1] = '\0';
    strncpy(nuovopilota->cognome, cognome, M - 1);
    nuovopilota->cognome[M - 1] = '\0';

    for (int i = 0; i < N; i++) {
        nuovopilota->posizioniGare[i] = posizioni[i];
    }

    int tabellaPunti[] = {25, 20, 16, 13, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2 , 1};
    nuovopilota->punteggioTotale = CalcolaPunteggio(nuovopilota->posizioniGare, tabellaPunti);
    nuovopilota->next = NULL;
    return nuovopilota;
}

Pilota* InserisciInOrdine(Pilota* h, Pilota* n){
    if (h == NULL || n->punteggioTotale > h->punteggioTotale) {
        n->next = h;
        return n;
    }
    Pilota* current = h;
    while (current->next != NULL && n->punteggioTotale <= current->next->punteggioTotale) {
        current = current->next;
    }
    n->next = current->next;
    current->next = n;
    return h;
}

void StampaClassifica(Pilota* h) {
    int posizione = 1;
    Pilota* current = h;
    while (current != NULL) {
        printf("%d. %s %s - %d pts.\n", posizione, current->nome, current->cognome, current->punteggioTotale);
        current = current->next;
        posizione++;
    }
}


void StampaClassificaInversaRicorsiva(Pilota* h){
    if (h == NULL) {
        return;
    }
    StampaClassificaInversaRicorsiva(h->next);
    printf("%s %s - %d pts.\n", h->nome, h->cognome, h->punteggioTotale);
}

void StampaMaxPodi(Pilota* h){
    if (h == NULL) {
        printf("Nessun pilota nella classifica.\n");
        return;
    }

    int maxPodi = -1;
    Pilota* best = NULL;
    Pilota* current = h;

    while (current != NULL) {
        int podiCount = 0;
        for (int i = 0; i < N; i++) {
            if (current->posizioniGare[i] >= 1 && current->posizioniGare[i] <= 3) {
                podiCount++;
            }
        }
        if (podiCount > maxPodi) {
            maxPodi = podiCount;
            best = current;
        }
        current = current->next;
    }

    if (best != NULL) {
        printf("\nPilota con il maggior numero di podi: %s %s con %d podi.\n", best->nome, best->cognome, maxPodi);
    } else {
        printf("Nessun pilota ha ottenuto podi.\n");
    }

}



Pilota* RimuoviPiloti(Pilota* h) {
    Pilota *current = h;
    Pilota *prev = NULL;
    Pilota *temp;
    int haDNF;

    while (current != NULL) {
        haDNF = 0;
        for (int i = 0; i < N; i++) {
            if (current->posizioniGare[i] == -1) {
                haDNF = 1;
                break;
            }
        }

        if (haDNF) {
            temp = current;
            if (prev == NULL) {
                h = current->next;
                current = current->next;
            } else {
                prev->next = current->next;
                current = current->next;
            }
            free(temp);
        } else {
            prev = current;
            current = current->next;
        }
    }
    return h;
}

void DistruggiClassifica(Pilota* h) {
    Pilota* temp;
    while (h != NULL) {
        temp = h;
        h = h->next;
        free(temp);
    }
}


int main(void) {
    Pilota *classifica = NULL;

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Max","Biaggi", (int[]){7, 3, 5, 5, 2, 6, 6, 4, -1, 4}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Nicky","Hayden", (int[]){-1, 7, 9, 6, 6, 5, 4, 1, -1, 3}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Valentino","Rossi", (int[]){1, 2, 1, 1, 1, 1, 1, 3, 1, 1}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Colin","Edwards", (int[]){9, 6, 8, 3, 9, 7, 3, 2, 4, 8}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Marco","Melandri", (int[]){3, 4, 3, 4, 4, 3, 2, -1, -1, 7}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Sete","Gibernau", (int[]){2, -1, 4, 2, -1, 2, 5, 5, -1, 2}));

    classifica = InserisciInOrdine(classifica,
        NuovoPilota("Loris","Capirossi", (int[]){13, 9, 12, 7, 3, 12, 10, 10, 6, 9}));

    printf("Classifica ordinata per punteggio.\n");
    StampaClassifica(classifica);

    printf("\nClassifica in Ordine Inverso.\n");

    StampaClassificaInversaRicorsiva(classifica);

    StampaMaxPodi(classifica);

    printf("\nRimozione dei piloti con DNF (Did Not Finish).\n");
    classifica = RimuoviPiloti(classifica);
    
    printf("Classifica dopo la rimozione dei piloti.\n");
    StampaClassifica(classifica);
    
    printf("\nDistruzione della classifica.\n");
    DistruggiClassifica(classifica);
    classifica = NULL;

    return 0;
}