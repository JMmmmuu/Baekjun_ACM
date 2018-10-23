#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, i;
    int x, y;

    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d%d", &x, &y);
        if (!(x == y || x - 2 == y) || x < 0 || y < 0) {
            printf("No Number\n");
            continue;
        }

        if (x == y)
            if (x % 2 == 0) printf("%d\n", x * 2);
            else printf("%d\n", (x / 2) * 4 + 1);
        else
            if (x % 2 == 0) printf("%d\n", x * 2 - 2);
            else printf("%d\n", x * 2 - 3);
    }

    return 0;
}
