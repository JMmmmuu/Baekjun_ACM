#include <stdio.h>
#include <stdlib.h>

int findMedian(int*, int);

int main() {
    int n, i, j;
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("%d\n", (int)((float)((sum / n) + 0.5)));
    printf("%d\n", findMedian(arr, n));


    int* good = (int*)calloc(n, sizeof(int));
    i = 0;
    while (i < n-1) {
        j = i;
        while (j + 1 < n && arr[j] == arr[j + 1]) {
            i++;
            j++;
        }



    }






    int cntMax = 0, cnt = 0, index = 0;
    while (i < n-1) {
        j = i;
        while (j+1 < n && arr[j] == arr[j + 1]) {
            cnt++;
            j++;
        }
        if (cnt > cntMax) {
            cntMax = cnt;
            index = --j;





        }
    }





}

int findMedian(int* list, int n) {
    int i, j, tmp;

    for (i = 1; i < n; i++) {
        j = i;
        tmp = list[j];
        while (j > 0 && tmp > list[j - 1]) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = tmp;
    }

    return list[n / 2];
}
