#include <stdio.h>
#include <stdlib.h>

enum direction{right, down};
int canYou(int** arr, int n, int row, int col, enum direction dir);

int main() {
    int n, i, j;
    scanf("%d", &n);
    int** arr = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) 
        arr[i] = (int*)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &arr[i][j]);

    canYou(arr, n, 0, 0, 0);



    enum direction dir = right;
    int blo = arr[0][0];
    int row=0, col=0;






    return 0;
}

int canYou(int** arr, int n, int row, int col, enum direction dir) {
    int i, j, blo;
    int** flag = (int**)malloc(n * sizeof(int));
    for(i = 0; i < n; i++)
        flag[i] = (int*)calloc(n, sizeof(int));

    while(flag[row][col] == 0) {
        blo = arr[row][col] % n;
    }





}
