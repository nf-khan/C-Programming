#include <stdio.h>

int main(void)
{
    int n;

    printf("Enter a number :");
    scanf("%d", &n);

    int sum = 0;
    while (1)
    {
        int a = n % 10;
        sum = sum + a;
        if (n / 10 == 0)
        {
            n = n / 10;
            printf("%d", sum);
            break;
        }
        else
        {
            n = n / 10;
        }
    }
}