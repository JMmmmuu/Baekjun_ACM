#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int isMagicSquare(int, int**);

int main()
{
    int n, i, j;
    scanf("%d", &n);
    int** square;

    square = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++)
        square[i] = (int*)calloc(n, sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) scanf("%d", &square[i][j]);
        

    printf("%d", isMagicSquare(n, square));

    return 0;
}

int isMagicSquare(int n, int** square)
{
    int res = 0, sum = n * (n*n + 1) / 2;
    int i, j;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            res += square[i][j];
        }
        if (res != sum) return FALSE;
    }
    return TRUE;
}

