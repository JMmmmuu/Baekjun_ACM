/*************************************************
 ***************** Self Number *******************
 ******************** Yuseok *********************
 ******************** 190608 *********************
 *************************************************/
#include <stdio.h>
#include <stdlib.h>

int d(int n) {
    int res = n;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    int num = 0;
    int i;
    int flag = 0;

    while (num <= 10000) {
        num++;
        flag = 0;
        for (i = 1; i < num; i++) {
            if (d(i) == num) {
                flag = 1;
                break;
            }
        }

        if (flag) continue;
        printf("%d\n", num);
    }

    return 0;
}
