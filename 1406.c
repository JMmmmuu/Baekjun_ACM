/*************************************************
 ******************** YUSEOK *********************
 ******************* @JMmmmuu ********************
 ****************** 2018.11.09 *******************
 ******************** EDITTER ********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {           // doubly linked list
    char item;
    nptr Llink;
    nptr Rlink;
} NODE;
nptr HEAD;

nptr pushInitItem(nptr curPos, char item);
nptr moveLeft(nptr curPos);
nptr moveRight(nptr curPos);
nptr delete(nptr curPos);
nptr pushCurPos(nptr curPos, char item);
void printList();
void freeList();

int main() {
    int i, n;
    char cmd, item;
    nptr curPos = HEAD;

    while ((item = fgetc(stdin)) != '\n')
        curPos = pushInitItem(curPos, item);
    curPos = pushInitItem(curPos, '\n');            // curPos point the last node of the list

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf(" %c", &cmd);
        switch (cmd) {
            case 'L' :
                curPos = moveLeft(curPos); break;
            case 'D':
                curPos = moveRight(curPos); break;
            case 'B':
                curPos = delete(curPos); break;
            case 'P':
                scanf(" %c", &item);
                curPos = pushCurPos(curPos, item); break;
        }
    }

    printList();
    freeList();

    return 0;
}

nptr pushInitItem(nptr curPos, char item) {
    nptr pNew = (nptr)malloc(sizeof(NODE));
    pNew->item = item;
    pNew->Llink = NULL; pNew->Rlink = NULL;

    if (!HEAD) HEAD = pNew;
    else {
        curPos->Rlink = pNew;
        pNew->Llink = curPos;
    }
    return pNew;
}

nptr moveLeft(nptr curPos) {
    if (!curPos->Llink) return curPos;
    return curPos->Llink;
}

nptr moveRight(nptr curPos) {
    if (!curPos->Rlink) return curPos;
    return curPos->Rlink;
}

nptr delete(nptr curPos) {
    if (!curPos->Llink) return curPos;

    nptr pFree = curPos->Llink;
    if (pFree->Llink) {
        nptr ptmp = pFree->Llink;
        ptmp->Rlink = curPos;
        curPos->Llink = ptmp;
    }
    else {
        // node to be freed is the HEAD Node!
        curPos->Llink = NULL;
        HEAD = curPos;
    }
    free(pFree);
    return curPos;
}

nptr pushCurPos(nptr curPos, char item) {
    if (!curPos) return NULL;

    nptr ptmp;
    nptr pNew = (nptr)malloc(sizeof(NODE));
    pNew->item = item;

    if (!curPos->Llink) {
        // push at the first
        pNew->Llink = NULL;
        pNew->Rlink = curPos;
        curPos->Llink = pNew;
        HEAD = pNew;
    }
    else {
        // push in the middle/ at the last
        ptmp = curPos->Llink;
        ptmp->Rlink = pNew;
        curPos->Llink = pNew;
        pNew->Llink = ptmp;
        pNew->Rlink = curPos;
    }
    
    return curPos;
}

void printList() {
    if(!HEAD) return;
    nptr ptmp = HEAD;
    for ( ; ptmp; ptmp = ptmp->Rlink)
        printf("%c", ptmp->item);
}
void freeList() {
    if(!HEAD) return;
    nptr pFree, ptmp;
    ptmp = HEAD;
    for ( ; ptmp->Rlink; ptmp = ptmp->Rlink) {
        pFree = ptmp->Llink;
        free(pFree);
    }
    free(ptmp);
}
