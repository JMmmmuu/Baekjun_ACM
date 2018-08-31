#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int timeSec(char a) {
    int sec;
    if (a < 'R') sec = (a - 'A') / 3 + 3;
    else {
        switch (a) {
            case 'S' : sec = 8; break;
            case 'T': case 'U': case 'V': sec = 9; break;
            case 'W': case 'X': case 'Y': case 'Z': sec = 10; break;
        }
    }
    //printf("%c %d %d\n", a, a-'A', sec);
    return sec;
}

int main()
{
    char* input = (char*)malloc(20 * sizeof(char));
    scanf("%s", input);

    int len = strlen(input);
    int i, elapsedTime = 0;

    for (i = 0; i < len; i++)
        elapsedTime += timeSec(input[i]);

    printf("%d\n", elapsedTime);

    free(input);
    return 0;
}
