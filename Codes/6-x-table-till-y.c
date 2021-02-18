#include <stdio.h>

void main()
{
    int x, y;
    printf("insert first numbers:");
    scanf("%d", &x);
    printf("insert second number:");
    scanf("%d", &y);

    for (int i = 1; i <= y; i++)
    {
        int z = x * i;
        printf("%d*%d=%d\n", x, i, z);
    }
}