#include <stdio.h>

int main()
{
	int input;
	scanf("%d", &input);

	int n = 0, temp = input;
	while (1) {
		input = (input < 10) ? input * 10 + input : (input / 10 + input % 10) % 10 + input % 10 * 10;
		n++;
		if (input == temp) break;
	}
	printf("%d\n", n);

	return 0;
}
