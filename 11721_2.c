/*
 * printf out 10 alphabet in a word each line
 */
#include <stdio.h>
#include <string.h>

int main()
{
    char input[101];
    scanf("%[^\n]s", input);
    int i, j, len = strlen(input);

    int m = len / 10;

    for (i = 0; i <= m; i++) {
        for (j = 0; j < 10; j++) {
            if (input[i * 10 + j] == '\0') break;
            printf("%c", input[i * 10 + j]);
        }
        printf("\n");
    }

    return 0;
}
