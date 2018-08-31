#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int howMuch(char*);

int main()
{
    char* input = (char*)malloc(16 * sizeof(char));
    scanf("%s", input);
    // printf("%s %d", input, strlen(input));

    printf("%d\n", howMuch(input));

    return 0;
}

int howMuch(char* input) {
    int n = strlen(input);
    int i, elapsedSec = 0;

    for (i = 0; i < n; i++) {
        switch(input[i]) {
            case 'A': case 'B': case 'C': elapsedSec += 3; break;
            case 'D': case 'E': case 'F': elapsedSec += 4; break;
            case 'G': case 'H': case 'I': elapsedSec += 5; break;
            case 'J': case 'K': case 'L': elapsedSec += 6; break;
            case 'M': case 'N': case 'O': elapsedSec += 7; break;
            case 'P': case 'Q': case 'R': case 'S': elapsedSec += 8; break;
            case 'T': case 'U': case 'V': elapsedSec += 9; break;
            case 'W': case 'X': case 'Y': case 'Z': elapsedSec += 10; break;
            default : break;
        }
    }
    return elapsedSec;
}
