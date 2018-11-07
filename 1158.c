#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    int num;
    nptr link;
} NODE;
nptr HEAD;

void push(int num);
nptr pop(nptr pCur, int num, int n);

int main() {
    int n, m;
    int i;

    scanf("%d%d", &n, &m);

    for (i = 0; i < n; i++)
        push(i+1);

    nptr pMove;
    for (pMove = HEAD; pMove->link; pMove = pMove->link) ;
    nptr pCur = pMove;
    printf("<");
    for (i = 0; i < n-1; i++)
        pCur = pop(pCur, m, n);
    printf("%d>\n", HEAD->num);

    free(HEAD);
    return 0;
}

void push(int num) {
    nptr pNew = (nptr)malloc(sizeof(NODE));
    pNew->num = num; pNew->link = NULL;

    if (!HEAD) HEAD = pNew;
    else {
        nptr pMove = HEAD;
        for(pMove = HEAD; pMove->link; pMove = pMove->link) ;
        pMove->link = pNew;
    }
}

nptr pop(nptr pCur, int num, int n) {
    if (!HEAD) return 0;
    nptr pRet = pCur, pFree;                // pFree is followed by pRet.
    for (int i = 0; i < num-1; i++)
        pRet = pRet->link ? pRet->link : HEAD;      // Move for (m-1) times. Move to the HEAD at the last node.

    pFree = pRet->link ? pRet->link : HEAD;         // pFree is to be popped. is followed by pRet.
    printf("%d, ", pFree->num);
    pRet->link = pFree->link ? pFree->link : HEAD;      // pRet is to be returned. will point Current Position.
    if (pFree == HEAD) HEAD = pFree->link ? pFree->link : NULL;     // if the pointed node is HEAD, move HEAD to the next NODE. assign NULL for bohum!!
    free(pFree);        // pop

    return pRet;
}
