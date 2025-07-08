#include <stdlib.h>
#include <stdio.h>

#include "list.h"

int main() {
    Player* lista;

    // creazione della lista iniziale
    lista = insertPlayer(NULL, newPlayer(0, "FastLane", (float[]){7.0, 8.5, 9.0, 8.5}));   
    lista = insertPlayer(lista, newPlayer(listLen(lista), "StackMaster", (float[]){6.0, 7.0, 7.5, 7.0}));
    lista = insertPlayer(lista, newPlayer(listLen(lista), "LoopHunter", (float[]){7.5, 8.5, 8.5, 7.5})); 
    lista = insertPlayer(lista, newPlayer(listLen(lista), "NullPointer", (float[]){5.0, 6.0, 5.5, 6.5}));
    lista = insertPlayer(lista, newPlayer(listLen(lista), "ZeroLag", (float[]){4.0, 5.0, 6.0, 5.5}));   
    lista = insertPlayer(lista, newPlayer(listLen(lista), "CodeSurfer", (float[]){9.0, 8.5, 9.5, 8.0}));
    lista = insertPlayer(lista, newPlayer(listLen(lista), "BugFinder", (float[]){3.0, 6.5, 7.0, 6.0})); 

    printf("Stampa lista inserita:\n");
    printList(lista);
    printf("\n");
    printf("Lunghezza della lista: %d\n", listLen(lista));
    printf("\n");

    // Creazione della lista dei top players
    float mediaTop = 8.0;
    Player* listaTopPlayers = createTopPlayersList(lista, mediaTop);

    printf("Lista dei top players con media superiore a %.2f, decrescente per media:\n", mediaTop);
    printList(listaTopPlayers);
    printf("\n");

    printf("Deallocazione lista...\n");    
    destroyList(lista);
    printf("Deallocazione lista dei top players...\n");
    destroyList(listaTopPlayers);

    return 0;
}
