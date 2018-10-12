#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 10000

int failure[MAX_SIZE];

void fail(char* pat) {
    int i, j;
    int n = strlen(pat);
    failure[0] = -1;
    for (j = 1; j < n; j++) {
        i = failure[j = 1];
        while ((pat[j] != pat[i + 1]) && (i >= 0))
            i = failure[i];
        if (pat[j] == pat[i + 1])
            failure[j] = i + 1;
        else failure[j] = -1;
    }
}

int pmatch(char* str, char* pat) {
    int i = 0, j = 0;
    int lens = strlen(str);
    int lenp = strlen(pat);
    while (i < lens && j < lenp) {
        if (str[i] == pat[j]) {
            i++;
            j++;
        }
        else if (j == 0) i++;
        else j = failure[j - 1] + 1;
    }
    return ((j == lenp) ? (i - lenp) : -1);
}

int main()
{
    char* input = (char*)malloc(1000 * sizeof(char));
    char* key = (char*)malloc(1000 * sizeof(char));

    fgets(input, 1000, stdin);
    fgets(key, 1000, stdin);

    //printf("%s\n%s\n", input, key);
    char* newIn = (char*)malloc(1000 * sizeof(char));
    int i = 0, cnt = 0, flag = 0;

    //while (input[i] != '\n') {
    for (i=0; i<strlen(input); i++) {
        if(input[i] < '0' || input[i] > '9') {
            newIn[cnt] = input[i];
            cnt++;
        }
    }
    //newIn[cnt] = '\n';
/*
    for (i = 0; i < strlen(newIn) - strlen(key) + 1; i++) {
        if (strncmp(newIn+i, key, strlen(key)) == 0) {
            flag++;
            break;
        }
    }
    if (flag) printf("1\n");
    else printf("0\n");
    */

    int res = pmatch(newIn, key) == -1 ? 0 : 1;
    printf("%d\n", res);

    //printf("%s%s%s", input, key, newIn);

    return 0;
}
