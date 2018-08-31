/*
 * group word checker
 * for example, ccazzzzbb is a group word
 * aaaabbccccc is a group word
 * aabbbcca is not a group word
 */
 #include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isGroup(char* str) {
    //if so return 1, else return 0
    int alp[26];
    int i, len = strlen(str), idx;

    if (len <= 0) {
        fprintf(stderr, "string error occured!\n");
        return 0;
    }
    if (len == 1) return 1;

    for (i = 0; i < 26; i++)
        alp[i] = 0;

    for (i = 0; i < len; i++) {
        idx = str[i] - 'a';
        if (!alp[idx]) alp[idx]++;
        else if (str[i] == str[i - 1]) continue;
        else return 0;
    }
    return 1;
}

int main()
{
    int N, i, count = 0;
    scanf("%d", &N);

    char** input;
    input = (char**)malloc(N * sizeof(char*));
    //char input[101];
    for (i = 0; i < N; i++) {
        //fgets(input, 101, stdin);
        input[i] = (char*)malloc(101 * sizeof(char));
        scanf(" %[^\n]s", input[i]);
        //printf("%s\n", input[i]);
        if (isGroup(input[i])) count++;
        //printf("%dth string is %d\n", i, isGroup(input[i]));
    }

    printf("%d\n", count);

    return 0;
}
