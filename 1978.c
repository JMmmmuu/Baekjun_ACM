/*************************************************
 ****************** find prime *******************
 ******************** Yuseok *********************
 ******************** 190206 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

int isPrime(int veri);

int main() {
    int n;
    scanf("%d", &n);

    int veri;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &veri);
        if (isPrime(veri)) cnt++;
    }

    printf("%d\n", cnt);

    return 0;
}

int isPrime(int veri) {
    /* O(n) algorithm */
    if (veri <= 1) return 0;
    for (int i = 2; i < veri; i++) {
        if (veri % i == 0) return 0;
    }
    return 1;
}
