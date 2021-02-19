#include <stdio.h>
int main()
{
    int n;

    printf("Enter first number :");
    scanf("%d", &n);
    int y = n;

    int num = 0;
    while (1)
    {
        int ans = n % 10;
        num = num + ans;
        if (n / 10 == 0)
        {
            break;
        }

        num = num * 10;
        n = n / 10;
    }
    if (num == y)

    {

        printf("palindrome number");
    }
    else
    {
        printf("no");
    }

    return 0;
}