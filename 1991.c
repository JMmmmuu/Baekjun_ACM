#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    char data;
    nptr LChild, RChild;
} Tree_Node;

nptr searchNode(char data);
void insertLeft(nptr par, char data);
void insertRight(nptr par, char data);

int main()
{
    char root, LC, RC;
    int line, i;

    scanf("%d", &line);

    for (i = 0; i < line; i++) {
        fgetc();
        scanf("%c %c %c", &root, &LC, &RC);
        if (LC != '.') inserLeft(
        if (LC == '.' && RC == '.') break;




    return 0;
}
