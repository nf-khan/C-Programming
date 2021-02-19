#include <stdio.h>
#define SIZE 3 

void input(int matrix[SIZE][SIZE]);
void output(int matrix[SIZE][SIZE]);
int main()
{
    int matrix1[SIZE][SIZE];
    int matrix2[SIZE][SIZE];
    int answer[SIZE][SIZE] = {0};

    input(matrix1);
    input(matrix2);

    output(matrix1);
    output(matrix2);

    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                answer[i][j] = answer[i][j] + (matrix1[i][k] * matrix2[k][j]);
            }
        }
    }
    //print answer
    output(answer);

    return 0;
}


void input(int matrix[SIZE][SIZE])
{
    printf("Insert values in matrix ;\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}
void output(int matrix[SIZE][SIZE])
{
    
    printf("Matrix :\n");
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}