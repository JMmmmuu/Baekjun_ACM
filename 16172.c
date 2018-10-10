#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char* input = (char*)malloc(1000 * sizeof(char));
    char* key = (char*)malloc(1000 * sizeof(char));

    fgets(input, 1000, stdin);
    fgets(key, 1000, stdin);

    //printf("%s\n%s\n", input, key);
    char* newIn = (char*)malloc(1000 * sizeof(char));
    int i = 0, cnt = 0, flag = 0;

    while (input[i] != '\n') {
        if(input[i] < '0' || input[i] > '9') {
            newIn[cnt] = input[i];
            cnt++;
        }
        i++;
    }
    newIn[cnt] = '\n';

    for (i = 0; i < strlen(newIn) - strlen(key) + 1; i++) {
        if (strncmp(newIn+i, key, strlen(key))) {
            flag++;
            break;
        }
    }
    if (flag) printf("1\n");
    else printf("0\n");


    printf("%s%s%s", input, key, newIn);

    return 0;
}
