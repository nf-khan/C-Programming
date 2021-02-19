#include <stdio.h>
#include <stdlib.h>

void input_array(int **arr, int rows, int cols);
void output_array(int **arr, int rows, int cols);
void deallocation(int **arr, int rows, int cols);
int main()
{
    int **arr1;
    int **arr2;
    int rows1, cols1;
    int rows2, cols2;
    int **answer;

    printf("Enter rows of the array 1: ");
    scanf("%d", &rows1);
    printf("Enter columns of the array 1: ");
    scanf("%d", &cols1);

    printf("Enter rows of the array 2: ");
    scanf("%d", &rows2);
    printf("Enter columns of the array 2: ");
    scanf("%d", &cols2);

    if (cols1 != rows2)
    {
        printf("can't proceed!");
        return 0;
    }
    else
    {

        arr1 = (int **)malloc(rows1 * sizeof(int *));

        for (int i = 0; i < rows1; i++)
        {
            arr1[i] = (int *)malloc(cols1 * sizeof(int));
        }

        input_array(arr1, rows1, cols1);

        arr2 = (int **)malloc(rows2 * sizeof(int *));

        for (int i = 0; i < rows2; i++)
        {
            arr2[i] = (int *)malloc(cols2 * sizeof(int));
        }

        input_array(arr2, rows2, cols2);

        output_array(arr1, rows1, cols1);
        output_array(arr2, rows2, cols2);

        answer = (int **)malloc(rows1 * sizeof(int *));

        for (int i = 0; i < rows1; i++)
        {
            answer[i] = (int *)malloc(cols2 * sizeof(int));
        }

        for (int i = 0; i < rows1; i++)
        {
            for (int j = 0; j < cols2; j++)
            {
                answer[i][j] = 0;
                for (int k = 0; k < rows2; k++)
                {
                    answer[i][j] = answer[i][j] + arr1[i][k] * arr2[k][j];
                }
            }
        }
        output_array(answer, rows1, cols2);
    }

    deallocation(arr1, rows1, cols1);
    deallocation(arr2, rows2, cols2);
    deallocation(answer, rows1, cols2);
    return 0;
}

void input_array(int **arr, int rows, int cols)
{
    printf("Input Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }
}

void output_array(int **arr, int rows, int cols)
{
    printf("Output Array:\n");

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void deallocation(int **arr, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        free(arr[i]);
    }
    free(arr);
}