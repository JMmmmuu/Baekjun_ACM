/*************************************************
 ******************* OX Score ********************
 ******************** Yuseok *********************
 ******************** 190000 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[80];
    int n;

    scanf("%d", &n);

    int sco = 0, cont = 0;
    for (int i = 0; i < n; i++) {
        sco = 0;
        cont = 0;
        memset(input, '\0', sizeof(input));

        scanf("%s", input);
        for (int idx = 0; input[idx]; idx++) {
            if (input[idx] == 'O')
                sco += ++cont;
            else cont = 0;
        }
        printf("%d\n", sco);
    }

    return 0;
}
