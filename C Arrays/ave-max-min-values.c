#include <stdio.h>

int main()
{

    int a[10];
    float sum = 0;

    // insert inputs in array

    printf("insert numbers\n");
    for (int i = 0; i < 10; i++)
    {

        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++)

    {

        printf("%d,", a[i]);
        sum = sum + a[i];
    }

    //for calculating average value

    printf("\n");
    printf("Average_value = sum / 10\n");
    printf("=%.0f/10\n", sum);
    float Average_value = sum / 10;
    printf("Average_value = %.2f\n", Average_value);

    //for calculating maximum value

    int index = 0;
    for (int i = 1; i < 10; i++)
    {
        if (a[i] > a[index])
            index = i;
    }
    printf("Maximum value =%d\n", a[index]);

    //for calculating minimum value

    index = 0;
    for (int i = 1; i < 10; i++)
    {
        if (a[i] < a[index])
            index = i;
    }
    printf("Minimum value =%d", a[index]);
    return 0;
}