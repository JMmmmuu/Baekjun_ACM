#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int howManyAlphabet(char*);

int main()
{
    char* input = (char*)malloc(101 * sizeof(char));
    scanf("%s", input);

    printf("%d\n", howManyAlphabet(input));
    return 0;
}

int howManyAlphabet(char* input) {
    int n = strlen(input);
    int i, cnt = 0;

    for (i = 0; i < n; i++) {
        if (i == n-1) {
            cnt++; break;
        }
        if (input[i] == 'c') {
            if (input[i + 1] == '=') i++;
            else if (input[i + 1] == '-') i++;
        }
        else if (input[i] == 'd') {
            if (input[i + 1] == '-') i++;
            else if (i + 2 <= n - 1) {
                if (input[i + 1] == 'z' && input[i + 2] == '=') i += 2;
            }
        }
        else if (input[i] == 'l' && input[i + 1] == 'j') i++;
        else if (input[i] == 'n' && input[i + 1] == 'j') i++;
        else if (input[i] == 's' && input[i + 1] == '=') i++;
        else if (input[i] == 'z' && input[i + 1] == '=') i++;
        cnt++;
    }
    return cnt;
}
