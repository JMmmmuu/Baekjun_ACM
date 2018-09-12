#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define SWAP(x, y) { int t; t = x; x = y; y = t; }

void ascendingSort(int*, int);
void  descendingSort(int*, int);
void printSum(int*, int*, int);

int main()
{
    int n, i;
    scanf("%d", &n);

    int* A = (int*)malloc(n * sizeof(int));
    int* B = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++) scanf("%d", &A[i]);
    for (i = 0; i < n; i++) scanf("%d", &B[i]);

    printSum(A, B, n);

    free(A);
    free(B);
    return 0;
}

void printSum(int* A, int* B, int n) {
    ascendingSort(A, n);
    descendingSort(B, n);

    int i, sum = 0;
    for (i = 0; i < n; i++)
        sum += A[i] * B[i];

    printf("%d\n", sum);
}

void ascendingSort(int* arr, int n) {
    int i, j;
    
    for (i = 0; i < n - 1; i++) {
        for (j = n - i - 1; j < n - 1; j++) {
            if (arr[j] > arr[j+1]) SWAP(arr[j], arr[j+1]); 
        }
    }
    for (i=0;i<n;i++) printf("%d\n", arr[i]);


}
void descendingSort(int* arr, int n) {


}
