#include <stdio.h>

//To calculate power
int power();

int main()
{
    int n;

    printf("insert a number:");
    scanf("%d", &n);
    int y = n;
    int a = n;

    int c = 0;
    while (1)
    {
        a = a / 10;
        c = c + 1;

        if (a == 0)
            break;
    }
    int sum = 0;
    while (1)
    {
        int b = n % 10;

        int p = power(b, c);

        sum = sum + p;

        if (n / 10 == 0)

            break;
        n = n / 10;
    }

    if (sum == y)
    {
        printf("Armstrong Number");
    }
    else
    {
        printf("no");
    }
}

//To calculate power
int power(int b, int c)
{
    int m;

    m = 1;

    for (int i = 1; i <= c; i++)
    {
        m = b * m;
    }
    return m;
}
