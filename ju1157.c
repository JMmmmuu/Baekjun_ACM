#include <stdio.h>
#include <string.h>

int main()
{
    char input[1000000];
    int alpha[26];
    scanf("%s", input);
    int len = strlen(input);

    int i, idx;
    for (i = 0; i < 26; i++) alpha[i] = 0;

    for (i = 0; i < len; i++) {
        if (input[i] < 'a')
            input[i] += ('a' - 'A');
        idx = input[i] - 'a';
        alpha[idx]++;
    }
    //printf("%s\n", input);
    /*
    for (i = 0; i < 26; i++)
        if (alpha[i]) 
            printf("alpha[%c] = %d\n", i + 'a', alpha[i]);
    */
    int max = 0, amax = 0;
    for (i = 1; i < 26; i++)
        if (alpha[max] <= alpha[i]) max = i;
    //printf("max is %c\n", max + 'a');
    if (max != 0) {
        for (i = 1; i < max; i++) {
            if (alpha[amax] <= alpha[i]) amax = i;
            if (alpha[amax] == alpha[max]) {
                printf("?\n"); return 0;
            }
        }
    }
    //printf("amax is %c\n", amax + 'a');
    printf("%c\n", 'A' + max);
    return 0;
}
