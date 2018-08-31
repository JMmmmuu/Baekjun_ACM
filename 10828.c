#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* nptr;
typedef struct node {
    int data;
    nptr link;
} NODE;
nptr HEAD = NULL;

int whatIsCommandInput(char*);
void push(char*);
void pop();
void size();
void empty();
void printTop();

int main()
{
    char* input;
    input = (char*)malloc(10 * sizeof(char));
    int n, i;

    scanf("%d", &n);
    fgetc(stdin);
    for(i = 0; i < n; i++) { 
        scanf(" %[^\n]s", input);
        switch(whatIsCommandInput(input)) {
            case 1: printTop(); break; //printf("1\n"); break;
            case 2: empty(); break; //printf("2\n"); break;
            case 3: size(); break; //printf("3\n"); break;
            case 4: pop(); break; //printf("4\n"); break;
            case 5: push(input); break; //printf("pushed %d\n", input[5] - '0'); break;
            default: fprintf(stderr, "Wrong Input\n");
        }
    }

    return 0;
}

int whatIsCommandInput(char* input) {
    if (strcmp("top", input) == 0) return 1;
    else if (strcmp("empty", input) == 0) return 2;
    else if (strcmp("size", input) == 0) return 3;
    else if (strcmp("pop", input) == 0) return 4;
    else if (strncmp("push", input, 4) == 0) return 5;
    else return 0;
}

void push(char* str) {
    nptr ptmp, pNew;
    pNew = (nptr)malloc(sizeof(NODE));
    sscanf(str, "%*s %d", &(pNew->data));
    pNew->link = NULL;

    if (!HEAD) HEAD = pNew;
    else {
        for (ptmp = HEAD; ptmp->link; ptmp = ptmp->link) ;
        ptmp->link = pNew;
    }
}

void pop() {
    if (!HEAD) {
        printf("-1\n");
        return;
    }
    nptr ptmp = HEAD;
    if (!(ptmp->link)) {
        printf("%d\n", ptmp->data);
        free(ptmp);
        HEAD = NULL;
    }
    else {
        for (ptmp = HEAD; ptmp->link->link; ptmp = ptmp->link) ;
        printf("%d\n", ptmp->link->data);
        free(ptmp->link);
        ptmp->link = NULL;
    }
}

void size() {
    int count = 0;
    if (!HEAD) {
        printf("0\n");
        return;
    }
    else {
        nptr ptmp;
        for (ptmp = HEAD; ptmp; ptmp = ptmp->link) count++;
        printf("%d\n", count);
    }
}

void empty() {
    if (!HEAD) printf("1\n");
    else printf("0\n");
}

void printTop() {
    if (!HEAD) {
        printf("-1\n");
        return;
    }
    else {
        nptr ptmp;
        for (ptmp = HEAD; ptmp->link; ptmp = ptmp->link) ;
        printf("%d\n", ptmp->data);
    }
}
