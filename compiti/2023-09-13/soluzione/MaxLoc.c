#include <stdio.h>
#include <stdlib.h>

struct Lista {
    int val;
    struct Lista * next;
};
typedef struct Lista LL;
LL * add(int, LL* );
int isLocMax(LL* , int );

LL * add(int num, LL* l) {
    LL* testa = (LL*)malloc(sizeof(LL));
    testa->val = num;
    testa->next = l;
    return testa;
}
int isLocMax(LL* h, int n) {
    if (h == NULL) {
        return 0;
    }
    LL* prec = NULL;
    LL* corr = h;
    LL* succ = h->next;

    while (succ != NULL) {
        if (corr->val == n &&
            (prec == NULL || prec->val < n) &&
            (succ->val < n )) {
            return 1;
        }
        prec = corr;
        corr = succ;
        succ = succ->next;
    }
    if (corr->val ==n && (prec==NULL || prec->val < n) ) return 1;
    return 0;  
}

int main(void) {
    int n;
    
    LL* l0=add(1,NULL);
    LL* l1=add(1,add(1,NULL));
    LL* l2=add(1,add(1,add(3,NULL)));
    LL* l3= add(9,add(1,add(3,add(2,add(6,NULL)))));
    n=1;
    if (isLocMax(l0, n)) {
        printf("%d e' locmax di l0 \n", n);
    } else {
        printf("%d non e' locmax di l0\n", n);
    }
    if (isLocMax(l1, n)) {
        printf("%d e' locmax di l1\n", n);
    } else {
        printf("%d non e' locmax di l1\n", n);
    }
    n = 3;
    if (isLocMax(l2, n)) {
        printf("%d e' locmax di l2\n", n);
    } else {
        printf("%d non e' locmax di l2\n", n);
    }
    if (isLocMax(l3, n)) {
        printf("%d e' locmax di l3\n", n);
    } else {
        printf("%d non e' locmax di l3 \n", n);
    }
    return 0;
}
