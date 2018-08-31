#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int T, len, i, j, k;
    char** input;
    
    scanf("%d", &T);
    input = (char**)malloc(T * sizeof(char*));
    for (i = 0; i < T; i++)
        input[i] = (char*)malloc(20 * sizeof(char));
    int R[T];
    //char** newString = (char**)malloc(T * sizeof(char*));

    for (i = 0; i < T; i++) {
        scanf("%d %[^\n]s", &R[i], input[i]);
        len = strlen(input[i]);
        //printf("R is %d, S is %s, len is %d\n", R, input[i], len);
        //newString[i] = (char*)malloc((R * len) * sizeof(char));
/*
        for (j = 0; j < len; j++)
            for (k = 0; k < R; k++)
                newString[i][j * R + k] = input[i][j];*/
        //printf("newS is %s\n", newString[i]);
    }

    for (i = 0; i < T; i++) {
        for (j = 0; j < strlen(input[i]); j++)
            for (k = 0; k < R[i]; k++) printf("%c", input[i][j]);
        printf("\n");
    }


    //for (i = 0; i < T; i++)
    //    printf("%s\n", newString[i]);

    free(input);
    //free(newString);
    return 0;
}
