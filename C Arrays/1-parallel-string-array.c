#include <stdio.h>

int main()
{

    char names[5][15];
    char Roll_number[5][15];
    float cgpa[5];

    // insert inputs in array

    for (int i = 0; i < 5; i++)
    {

        printf("Roll_number:");
        scanf("%s", &Roll_number[i]);

        printf("names: ");
        scanf("%s", &names[i]);

        printf("cgpa:");
        fflush(stdin);
        scanf("%f", &cgpa[i]);
    }
    printf("\n\n");

    for (int i = 0; i < 5; i++)
    {
        printf("%s\t", Roll_number[i]);
        printf("%s\t", names[i]);
        printf("%.2f\n", cgpa[i]);
    }
    return 0;
}
