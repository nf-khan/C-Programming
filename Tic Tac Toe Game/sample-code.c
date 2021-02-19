#include <stdio.h>
#include <stdbool.h>

int insert_position(char board[3][3]);
void output(char board[3][3]);
void input_name(char names[2][15]);
bool invalid_input(char board[3][3], int input);
bool decision(char board[3][3]);

int main()
{
    printf("\nThis is TIC TAC TOE!\n\n");

    int play_again;
    char board[3][3];
    char name[2][15];
    char symbol1;
    char symbol2;
    bool is_win;
    int input;

    input_name(name);
    printf("\n%s choose your symbol either X or O: ", name[0]);
    fflush(stdin);
    scanf("%c", &symbol1);

    symbol2 = symbol1 == 'X' ? 'O' : 'X';

    while (true)
    {
        // start with empty board
        for (int row = 0; row < 3; row++)
        {
            for (int col = 0; col < 3; col++)
            {
                board[row][col] = ' ';
            }
        }

        printf("\nLet's start the game!\n\n");
        output(board);

        for (int k = 0; k < 9; k++)
        {
            int row, col, l;
            l = k % 2 == 0 ? 0 : 1;

            printf("%s's turn:\n", name[l]);
            input = insert_position(board);

            row = (input - 1) / 3;
            col = (input - 1) % 3;

            board[row][col] = l == 0 ? symbol1 : symbol2;

            output(board);

            is_win = decision(board);
            if (is_win == true)
            {
                printf("CONGRATULATIONS!\n%s you have WON the GAME!\n", name[l]);
                 printf("GAME END!\n");
                break;
            }

            // Game Draw
            if (k == 8)
            {
                printf("GAME DRAW!\n");
                 printf("GAME END!\n");
                break;
            }

        }

        // play again
        printf("\nDo you want to play again?\nPress 1 for YES and 0 for NO. ");
        scanf("%d", &play_again);

        if (play_again != 1)
        {
            break;
        }
    }

    return 0;
}

void output(char board[3][3])
{
    printf("\n\n");

    for (int row = 0; row < 3; row++)
    {
        for (int col = 0; col < 3; col++)
        {
            printf(" %c ", board[row][col]);

            if (col < 2)
            {
                printf("|", board[row][col]);
            }
        }

        printf("\n");

        if (row < 2)
        {
            printf("------------\n");
        }
        else
        {
            printf(" ");
        }
    }

    printf("\n\n");
}

int insert_position(char board[3][3])
{
    int input;
    bool is_invalid_input;

    scanf("%d", &input);
    while (true)
    {
        is_invalid_input = invalid_input(board, input);

        if (is_invalid_input)
        {
            printf("Please enter some other number\n");
            scanf("%d", &input);
        }
        else
        {
            break;
        }
    }

    return input;
}

void input_name(char names[2][15])
{
    names[2][15];
    for (int i = 0; i < 2; i++)
    {
        printf("Player %d:Enter name\n", i + 1);
        scanf("%s", &names[i]);
    }
}

bool invalid_input(char board[3][3], int input)
{
    int row, col;
    row = (input - 1) / 3;
    col = (input - 1) % 3;

    while (board[row][col] != ' ')
    {
        if (input > 0 && input < 10)
        {
            printf("Repeated Input!\n");
        }

        if (input == 0 || input > 10)
        {
            printf("Only enter number from 1-9\n");
        }
        return true;
    }

    return false;
}

bool decision(char board[3][3])
{
    //rows verification
    for (int row = 0; row < 3; row++)
    {
        for (int col = 1; col < 3; col++)
        {
            if ((board[row][col] != board[row][col - 1]) || (board[row][col] == ' '))
            {
                break;
            }

            if (col == 2)
            {
                return true;
            }
        }
    }

    //column verification
    for (int row = 0; row < 3; row++)
    {
        for (int col = 1; col < 3; col++)
        {
            if ((board[col][row] != board[col - 1][row]) || (board[col][row] == ' '))
            {
                break;
            }

            if (col == 2)
            {
                return true;
            }
        }
    }

    // Daigonal verification
    for (int row = 1; row < 3; row++)
    {
        if ((board[row][row] != board[row - 1][row - 1]) || (board[row][row] == ' '))
        {
            break;
        }

        if (row == 2)
        {
            return true;
        }
    }

    //Diagonal 2
    int row = 0;
    for (int col = 2; col >= 0; col--)
    {
        if ((board[row + 1][2 - (row + 1)] != board[row][col]) || (board[row][col] == ' '))
        {
            break;
        }

        if (row == 1)
        {
            return true;
        }
        row = row + 1;
    }

    return false;
}
