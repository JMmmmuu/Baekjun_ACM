#include <stdio.h>

int main()
{
    int a, b, c, mul, idx;
    int arr[10];

    for (idx = 0; idx < 10; idx++) arr[idx] = 0;
    scanf("%d%d%d", &a, &b, &c);
    mul = a * b * c;

    while ( mul ) {
        idx = mul % 10;
        arr[idx]++;
        mul /= 10;
    }
    for (idx = 0; idx < 10; idx++) printf("%d\n", arr[idx]);

    return 0;
}
