/*************************************************
 ********************* HanSu *********************
 ******************** Yuseok *********************
 ******************** 190608 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

int isHansu(int n) {
    if (n < 100) return 1;

    int digit = 0;
    int n1, n2;
    n1 = n % 10;
    n2 = n % 100 / 10;
    n /= 100;
    int gap = n1 - n2;

    int flag = 0;

    do {
        n1 = n2;
        n2 = n % 10;
        if (n1 - n2 != gap) {
            flag = 1;
            break;
        }
        n /= 10;
    } while (n > 0);

    return 1 - flag;
}

int main() {
    int N;
    scanf("%d", &N);

    if (N < 100)
        printf("%d\n", N);
    else {
        int cnt = 99;
        for (int i = 100; i <= N; i++)
            cnt += isHansu(i);
        
        printf("%d\n", cnt);
    }


    return 0;
}
