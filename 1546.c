#include <stdio.h>
#include <stdlib.h>

float findM(float*, float);

int main()
{
	float n, m;
	int i;
	float *p;
	float sum = 0, avg;

	scanf("%f", &n);
	p = (float*)malloc(n * sizeof(float));

	for (i = 0; i < n; i++) {
		scanf("%f", &p[i]);
	}
	m = findM(p, n);
	
	for (i = 0; i < n; i++) {
		p[i] = p[i] / m * 100;
	}

	for (i = 0; i < n; i++) {
		sum += p[i];
	}
	avg = sum / n;

	printf("%.2f\n", avg);


	return 0;
}

float findM(float* p, float n)
{
	int i;
	float max = p[0];

	for (i = 0; i < n; i++) {
		if (max < p[i]) max = p[i];
	}

	return max;
}
