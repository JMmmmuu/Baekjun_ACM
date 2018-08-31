#include <stdio.h>

int main()
{
	int N;
	int maxf;
	int i;
	int resf, rest;

	scanf("%d", &N);


	for(i = N/5; i >= 0; i--) {
		if ((N - 5*i) % 3 == 0) break;
		if (i == 0 && (N - 5*i) % 3 != 0) {
			printf("-1\n");
			return 0;
		}
	}
	
	resf = i;
	rest = (N - 5*i) / 3;

	printf("five : %d\nthree : %d\ntotal : %d\n", resf, rest, resf + rest);
	

	return 0;
}
