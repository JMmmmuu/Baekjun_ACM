/*************************************************
 ******************** YUSEOK *********************
 ******************* @JMmmmuu ********************
 ****************** 2018.08.10 *******************
 ***************** QUEUE - BASIC *****************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nptr;
typedef struct node {
    int data;
    nptr link;
} NODE;

nptr HEAD;

int whatIsCommand(char*);
void push(char*); // 5
void pop();     // 0
void front();    // 1
void back();     // 2
void empty();    // 3
void size();     // 4

int main()
{
    int n, i;
    char* input = (char*)malloc(10 * sizeof(char));

    scanf("%d", &n);
    fgetc(stdin);
    for (i=0; i<n; i++) {
        scanf(" %[^\n]s", input);
        switch(whatIsCommand(input)) {
            case 0: pop(); break;
            case 1: front(); break;
            case 2: back(); break;
            case 3: empty(); break;
            case 4: size(); break;
            case 5: push(input); break;
            default: printf("wrong input\n");
        }
    }


    return 0;
}

int whatIsCommand(char* input) {
    if (strcmp(input, "pop") == 0) return 0;
    else if (strcmp(input, "front") == 0) return 1;
    else if (strcmp(input, "back") == 0) return 2;
    else if (strcmp(input, "empty") == 0) return 3;
    else if (strcmp(input, "size") == 0) return 4;
    else return 5;
}

void push(char* input) {
    nptr pNew = (nptr)malloc(sizeof(NODE));
    sscanf(input, "%*s %d", &(pNew->data));
    pNew->link = NULL;

    if (!HEAD) HEAD = pNew;
    else {
        nptr mv = HEAD;
        for (; mv->link; mv = mv->link) ;
        mv->link = pNew;
    }
}

void pop() {
    if (!HEAD) {
        printf("-1\n");
        return;
    }
    else {
        nptr tmp = HEAD;
        HEAD = tmp->link;
        printf("%d\n", tmp->data);
        free(tmp);
        return;
    }
}

void front() {
    if (!HEAD) printf("-1\n");
    else printf("%d\n", HEAD->data);
}

void back() {
    if (!HEAD) printf("-1\n");
    else {
        nptr mv = HEAD;
        for (; mv->link; mv = mv->link) ;
        printf("%d\n", mv->data);
    }
}

void empty() {
    if (!HEAD) printf("1\n");
    else printf("0\n");
}

void size() {
    int cnt = 0;
    nptr mv;
    for (mv = HEAD; mv; mv = mv->link) cnt++;
    printf("%d\n", cnt);
}

