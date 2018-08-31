#include <stdio.h>

int main()
{
    int n, res;
    scanf("%d", &n);
    res = (n % 5 == 0) ? n / 5 : n / 5 + 1;

    printf("%d\n", res);
    return 0;
}
