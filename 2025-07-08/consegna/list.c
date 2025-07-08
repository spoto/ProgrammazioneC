#include "list.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Player *newPlayer(int id, const char nickname[], float *best_scores) {
    // Da completare
}

int listLen(Player *head) {
    // Da completare, deve essere iterativa
}

Player* insertPlayer(Player* head, Player* n){
    // Da completare
}

Player* insertInOrder(Player *head, Player *n){
    // Da completare
}


float getMean(float best_scores[]) {
    // Da completare
}

Player* createTopPlayersList(Player *head, float mediaTop) {
    // Da completare, deve essere ricorsiva
}

void printList(Player *head) {
    // Da completare
}

void destroyList(Player *head) {
    // Da completare
}
