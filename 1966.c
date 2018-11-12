/*********************************************
 ****************** YUSEOK *******************
 ***************** @JMmmmuu ******************
 **************** 2018.11.12 *****************
 *********************************************/

#include <stdio.h>
#include <stdlib.h>

typedef struct node* nptr;
typedef struct node {
    int key;        // node we want to know!
    int pri;        // priority
    nptr link;
} NODE;
nptr QUEUE;

nptr enqueue(nptr ptmp, int pri);
int dequeue(int pri);
void moveNode(nptr ptmp);
void freeQueue();
void insertionSort(int* data, int size);

int main() {
    int testCase, N, M, data, cnt;
    int i, j;
    int* priority;
    scanf("%d", &testCase);
    nptr last;
    
    for (i = 0; i < testCase; i++) {
        // iterate for testCase times
        cnt = 0;        // how many dequeue??
        last = QUEUE;   // save last node of the QUEUE

        scanf("%d %d", &N, &M);
        priority = (int*)malloc(N * sizeof(int));
        for (j = 0; j < N; j++) {
            scanf("%d", &data);
            last = enqueue(last, data);
            priority[j] = data;
            
            if (j == M) last->key = 1;      // save key == 1 for wanted node
        }

        insertionSort(priority, N);     // save priority in non-increasing order
        
        data = dequeue(priority[cnt]);
        cnt++;
        while (QUEUE && !data) {        // escape loop whehn the data(key) is 1
            data = dequeue(priority[cnt]);
            cnt++;
        }

        printf("%d\n", cnt);
        freeQueue();            // free all remainig nodes in QUEUE
        free(priority);         // free array
    }

    return 0;
}

nptr enqueue(nptr ptmp, int pri) {
    // add node at the last
    nptr pNew = (nptr)malloc(sizeof(NODE));
    pNew->pri = pri; pNew->key = 0; pNew->link = NULL;

    if (!QUEUE) QUEUE = pNew;
    else ptmp->link = pNew;

    return pNew;
}

int dequeue(int pri) {
    // if wanted node is dequeued, return 1
    if (!QUEUE) return 1;
    if (!QUEUE->link) return 1;

    nptr last, ptmp;
    for (last = QUEUE; last->link; last = last->link) ;
    while (QUEUE->pri != pri) {
        
        ptmp = QUEUE;
        QUEUE = ptmp->link;
        last->link = ptmp;
        ptmp->link = NULL;
        last = ptmp;
    }

    ptmp = QUEUE;
    QUEUE = ptmp->link;
    int key = ptmp->key;
    free(ptmp);

    return key;
}

void freeQueue() {
    nptr pFree;
    while (QUEUE) {
        pFree = QUEUE;
        QUEUE = QUEUE->link;
        free(pFree);
    }
}

void insertionSort(int* data, int size) {
    // Since size of data is under 100, use insertion sort
    int i, j, tmp;

    for (i = 1; i < size; i++) {
        j = i;
        tmp = data[i];
        while (j > 0 && tmp > data[j - 1]) {
            data[j] = data[j - 1];
            j--;
        }
        data[j] = tmp;
    }
}

