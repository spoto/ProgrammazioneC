#include <stdio.h>
#include <stdlib.h>
typedef struct elem {
     int data;
     struct elem * next;
 } Elem;

 Elem* crealista(int arr[], int size);
 void printList(Elem* head);


 int main(void) {
     int arr[] = {2,4,4,4,4,6,6,8,8,8,10,10,10};
     int arr1[] = {2};
     int size = sizeof(arr) / sizeof(int);
     Elem* result = crealista(arr, size);
     printf("Lista senza duplicati: ");
     printList(result);
     return 0;
 }

 Elem* crealista(int arr[], int size) {
     Elem* testa = NULL;
     int i=size-1;
     int j=size-2;
     while(i>=0){
         while(j>=0 && arr[j]==arr[i])j--;
         Elem * p= (Elem*)malloc(sizeof(Elem));
         p->data = arr[i];
         p->next = testa;
         testa=p;
        i=j;
     }
     return testa;
 }
 void printList(Elem* head) {
     Elem* temp = head;
     while (temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
     }
     printf("\n");
 }
