#include <stdio.h>
#include <stdlib.h>

void sort(int*, int);
void printList(int* list, int n) {
    for (int i = 0; i < n; i++)
        printf("%d", list[i]);
    printf("\n");
}

int main() {
    char ch;
    int* list = (int*)malloc(10000 * sizeof(int));
    int i = 0;

    while ( (ch = getchar()) != '\n' ) {
        list[i] = ch - '0';
        i++;
    }
    sort(list, i);
    printList(list, i);

    return 0;
}

void sort(int* list, int n) {
    int i, j, tmp;

    for (i = 1; i < n; i++) {
        j = i;
        tmp = list[j];
        while (j > 0 && list[j - 1] < tmp) {
            list[j] = list[j - 1];
            j--;
        }
        list[j] = tmp;
    }
}
