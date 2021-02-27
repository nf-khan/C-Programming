#include <stdio.h>

int main()
{
    int n, y;
    printf("insert a number:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)

    {
        int y = i * 2;
        printf("%d\n", y);
    }
}