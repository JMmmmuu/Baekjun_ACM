/*
 * find out how many words are in the string.
 * input consists of alphabet, and space.
 */
#include <stdio.h>
#include <string.h>

int getNumWord(char* input) {
    int len = strlen(input), i;
    int count = 0;
    for (i = 0; i < len; i++) {
        if (input[i] == ' ') {
            if (i == 0) {       // blank at the start
                //while (input[i] != ' ') { i++; }
                i++;
                //count++;
            }
            else count++;
        }
    }
    if (input[len - 1] == ' ') count--;
    return ++count;
}

int main()
{
    char input[1000001];
    //fgets(input, 1000001, stdin);
    scanf("%[^\n]s", input);

    printf("%d\n", getNumWord(input));

    return 0;
}
