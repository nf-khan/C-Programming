#include <stdio.h>

int main()
{
    int a, b;
    printf("put first integer:");
    scanf("%d", &a);

    printf("put second integer:");
    scanf("%d", &b);

    int sum = a + b;
    printf("Sum is=%d", sum);

    return 0;
}