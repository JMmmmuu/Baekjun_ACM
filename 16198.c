#include <stdio.h>
#include <stdlib.h>

int countScore(int*, int);

int main() {
    int n, i;
    scanf("%d", &n);
    int* energy = (int*)malloc(n * sizeof(n));
    for (i = 0; i < n; i++)
        scanf("%d", &energy[i]);

    printf("%d\n", countScore(energy, n));

    return 0;
}

int countScore(int* energy, int n) {
    int i, MaxScore = 0, MaxIndex = 1;
    int score=0;

    while (n != 2) {
        MaxScore = 0;
        for (i = 1; i < n-1; i++) {
            if (energy[i-1] * energy[i+1] > MaxScore) {
                MaxScore = energy[i-1] * energy[i+1];
                MaxIndex = i;
                //printf("%d %d %d\n", i, energy[i], MaxScore);
            }
        }
        if (n == 3) MaxScore = energy[0] * energy[2];
        score += MaxScore;
        //printf("%d\n", score);
        i = MaxIndex;
        while (i < n - 1) {
            energy[i] = energy[i + 1];
            i++;
        }
        n--;
    }

    return score;
}
