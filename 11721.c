#include <stdio.h>
#include <stdlib.h>

int main()
{
	char input[100];

	scanf("%[^\n]s", input);

	int i, j;
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			printf("%c", input[10 * i + j]);
			if (input[10 * i + j] == '\0') {
				printf("\n");
				return 0;
			}
		}
		printf("\n");
	}

	return 0;
}
