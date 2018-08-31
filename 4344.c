#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, j;
	float sum;
	int *np, *sco;
	double avg;
	double *p, *per;

	scanf("%d", &n);
	np = (int*)malloc(n * sizeof(int));
	per = (double*)malloc(n * sizeof(double));
	sco = (int*)malloc(sizeof(int));

	for (i = 0; i < n; i++) {
		scanf("%d", &np[i]);
		sco = (int*)realloc(sco, np[i] * sizeof(int));
		int sum = 0;
		int ss = 0;
		for (j = 0; j < np[i]; j++) {
			scanf("%d", &sco[j]);
			sum += sco[j];
		}
		avg = (double)sum / np[i];

		for (j = 0; j < np[i]; j++) {
			if (sco[j] > avg) ss++;
		}
		per[i] = ss / (double)np[i] * 100;

	}


	for (i = 0; i < n; i++) {
		printf("%.3lf\%\n", per[i]);
	}

	return 0;
}
