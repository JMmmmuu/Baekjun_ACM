#include <stdio.h>

int main()
{
    int i, j;
    int n, m;
    scanf("%d", &n);
    m = n;
    
    for (n = n; n > 0; n--) {
        for (i = 0; i < n - 1; i++) {
            printf(" ");
        }
        for (j = 0; j < m - n + 1; j++) {
            printf("*");
        }
        printf("\n");
    }
    
    return 0;
}
