#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node* PS_ptr;
typedef struct node {
    int PS;     // 0 for (), 1 for []
    PS_ptr link;
} PS_node;

typedef struct Node* oper_ptr;
typedef struct Node {
    int score;
    int oper;   // 1 for +, 2 for *, 0 for nothing
    oper_ptr link;
} Score_node;

PS_ptr PS_header;
oper_ptr Score_header;

PS_ptr top() {     // return top node
    PS_ptr move;
    for (move = PS_header; move->link; move = move->link) ;
    return move;
}

void push_PS(char ps) {
    PS_ptr pNew = (PS_ptr)malloc(sizeof(PS_node));
    (ps == '(') ? pNew->PS = 0 : pNew->PS = 1;
    pNew->link = NULL;

    if ( !PS_header ) PS_header = pNew;
    else {
        PS_ptr mv;
        for (mv = PS_header; mv->link; mv = mv->link) ;
        mv->link = pNew;
    }
}

void push_oper(int scr, int oper) {

}


    


int main()
{
    char ch;
    PS_header = NULL;
    Score_header = NULL;

    while ( (ch = fgetc(stdin)) != '\n' ) {
        switch (ch) {
            case '(':

            case ')':

            case '[':

            case ']':

            default: printf("wrong input\n"); return 0;
        }
    }




    return 0;
}


