#include <stdio.h>
#include <stdlib.h>

int bigger(int a, int b) { return a > b ? a : b; }

int main() {
    int n, i, j;

    scanf("%d", &n);
    int** tri = (int**)malloc(n * sizeof(int*));
    int** cnt = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        tri[i] = (int*)malloc((i+1) * sizeof(int));
        cnt[i] = (int*)calloc((i+1), sizeof(int));
    }

    for (i = 0; i < n; i++)
        for (j = 0; j <= i; j++)
            scanf("%d", &tri[i][j]);

    cnt[0][0] = tri[0][0];

    for (i = 1; i < n; i++) {
        for (j = 0; j <= i; j++) {
            if (j == 0) cnt[i][j] = cnt[i-1][j] + tri[i][j];
            else if (j == i) cnt[i][j] = cnt[i-1][j-1] + tri[i][j];
            else cnt[i][j] = bigger(cnt[i-1][j-1], cnt[i-1][j]) + tri[i][j];
        }
    }

    int max = 0;
    for (i = 0; i < n; i++) {
        if (max < cnt[n-1][i]) max = cnt[n-1][i];
    }
    printf("%d\n", max);

    for (i = 0; i < n; i++) {
        free(tri[i]);
        free(cnt[i]);
    }
    free(tri);
    free(cnt);
    return 0;
}
