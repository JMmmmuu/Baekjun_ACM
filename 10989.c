#include <stdio.h>
#include <stdlib.h>
#define less(x, y) x < y
#define SWAP(x, y) { int tmp = x; x = y; y = tmp; }
#define cmpSWAP(x, y) { if (less(y, x)) SWAP(y, x) }

void quickSort(int*, int, int);
int partition(int*, int, int);
void printList(int* list, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", list[i]);
    printf("\n");
}

int main() {
    int n, i;
    scanf("%d\n", &n);
    int* list = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
        scanf("%d", &list[i]);

    printList(list, n);
    quickSort(list, 0, n-1);
    printList(list, n);

    free(list);
    return 0;
}

void quickSort(int* list, int left, int right) {
    if (left >= right) return;

    int pivot = partition(list, left, right);
    quickSort(list, left, pivot - 1);
    quickSort(list, pivot + 1, right);
}

int partition(int* list, int left, int right) {
    int pivot, i, pIndex = 0, tmpIndex;
    //int mid = (left + right) / 2;

    /*
    cmpSWAP(list[left], list[mid]);
    cmpSWAP(list[left], list[right]);
    cmpSWAP(list[mid], list[right]);
*/

    pivot = list[right];
    pIndex = left;
    for(i = left; i < right; i++) {
        if (list[i] <=  pivot) {
            //if (list[i] == pivot) tmpIndex = pIndex;
            SWAP(list[i], list[pIndex]);
            pIndex++;
        }
    }
    //pIndex--;
    SWAP(list[pIndex], list[right]);

    return pIndex;
}
