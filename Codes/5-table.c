#include <stdio.h>

int main()
{
    int n;
    printf("insert a number:");
    scanf("%d", &n);

    for (int i = 1; i <= 10; i++)
    {
        int answer = n * i;
        printf("%d*%d=%d\n", n, i, answer);
    }
}