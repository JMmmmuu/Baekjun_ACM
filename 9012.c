/*************************************************
 ******************** YUSEOK *********************
 ******************* @JMmmmuu ********************
 ****************** 2018.08.06 *******************
 ****************** PARENTHESIS ******************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    char PS;
    nptr link;
} NODE;
nptr pHeader;

void push(char PS) {
    nptr pNew = (nptr)malloc(sizeof(NODE));
    pNew->PS = PS;
    pNew->link = NULL;
    if (!pHeader) pHeader = pNew;
    else {
        nptr ptmp;
        for (ptmp = pHeader; ptmp->link; ptmp = ptmp->link) ;
        ptmp->link = pNew;
    }
    //printf("\npushed\n");
}

void pop() {
    if (!pHeader) return; //{ printf("empty\n"); return; }
    else {
        nptr ptmp = pHeader;
        if (!(ptmp->link)) {
            free(ptmp);
            pHeader = NULL;
        }
        else {
            for (ptmp = pHeader; ptmp->link->link; ptmp = ptmp->link) ;
            free(ptmp->link);
            ptmp->link = NULL;
        }
        //printf("\npoped\n");
        return;
    }
}

int main()
{
    int i, n, flag;
    scanf("%d\n", &n);

    char ch;
    
    for (i = 0; i < n; i++) {
        pHeader = NULL;
        flag = 0;

        while( (ch = fgetc(stdin)) != '\n' ) {
            switch (ch) {
                case '(':
                    push(ch); break;
                case ')':
                    if (!pHeader) flag = 1;
                    pop(); break;
                default: printf("wrong input\n");
            }
        }
        if (pHeader || flag) printf("NO\n");

        else printf("YES\n");
    }

    return 0;
}
