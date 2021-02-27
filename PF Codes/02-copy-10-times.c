#include <stdio.h>

int main()
{
    int a;
    printf("insert a integer:");
    scanf("%d", &a);

    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", a);
    }
    return 0;
}