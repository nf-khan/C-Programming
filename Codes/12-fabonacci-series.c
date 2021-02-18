#include <stdio.h>

int main(void)
{
    int n;
    printf("insert a number:");
    scanf("%d", &n);

    int x = 1;
    int sum = 0;
    int num;
    for (int i = 0; i < n; i++)
    {
        int num = sum;
        printf("%d\n", num);
        sum = num + x;
        x = num;
    }
}