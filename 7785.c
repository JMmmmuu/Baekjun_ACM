/*************************************************
 *************************************************
 ******************** Yuseok *********************
 ******************** 190218 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node* nptr;
typedef struct node {
    char name[6];
    nptr link;
} Log;

nptr head;
nptr push(nptr last, char* name);
void pop(char* name);

int main() {
    int i, n;
    char name[6];
    char remain[6];

    scanf("%d", &n);
    head = NULL;
    nptr last = head;
    for (i = 0; i < n; i++) {
        scanf(" %s %s", name, remain);
        if ( !strcmp(remain, "enter") ) // if entered
            last = push(last, name);
        else // leave
            pop(name);
    }

    nptr pMove;
    for (pMove = head; pMove; pMove = pMove->link) {
        printf("%s\n", pMove->name);
    }

    return 0;
}

nptr push(nptr last, char* name) {
    nptr pNew = (nptr)malloc(sizeof(Log));
    strcpy(pNew->name, name);
    pNew->link = NULL;

    if (!head) {
        head = pNew;
        return head;
    }
    else {
         last->link = pNew;
         return pNew;
    }
}

void pop(char* name) {
    if (!head)
        return;
    else {
        nptr pMove, pFree;
        if (head) {
            if ( !strcmp(head->name, name) ) {
                pFree = head;
                head = pFree->link;
                free(pFree);
            }
            else
                for (pMove = head; pMove->link; pMove = pMove->link)
                    if (!strcmp(pMove->link->name, name)) {
                        pFree = pMove->link;
                        pMove->link = pFree->link;
                        free(pFree);
                        break;
                    }
        }
    }
}
