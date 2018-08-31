#include <stdio.h>
#include <string.h>

int main()
{
    char input[100];
    scanf("%s", input);

    int alpha[26];
    int i;
    for (i = 0; i < 26; i++)
        alpha[i] = -1;

    int count = 0;
    int len = strlen(input);
    int idx;
    for (i = 0; i < len; i++) {
        idx = input[i] - 'a';
        if (alpha[idx] == -1)
            alpha[idx] = i;
    }
    for (i = 0; i < 26; i++)
        printf("%d ", alpha[i]);
    printf("\n");

    return 0;
}
