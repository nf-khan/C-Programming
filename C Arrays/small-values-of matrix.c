#include <stdio.h>

int main()
{
    //ARRAY 1
    float a1[3];

    printf("insert numbers in array 1\n");

    for (int i = 0; i < 3; i++)
    {
        scanf("%f", &a1[i]);
    }
    printf("a1[10]=");
    for (int i = 0; i < 3; i++)
    {

        printf("%.2f,", a1[i]);
    }
    printf("\n");

    //ARRAY2
    float a2[3];

    printf("insert numbers in array 2\n");

    for (int i = 0; i < 3; i++)
    {
        scanf("%f", &a2[i]);
    }
    printf("a2[10]=");
    for (int i = 0; i < 3; i++)

    {

        printf("%.2f,", a2[i]);
    }
    printf("\n");
    printf("The values of a1 smaller than any element of a2=");

    for (int j = 0; j < 3; j++)
    {
        for (int i = 0; i < 3; i++)

        {

            if (a2[i] > a1[j])
            {
                printf("%.2f,", a1[j]);
                break;
            }
        }
    }
    return 0;
}
