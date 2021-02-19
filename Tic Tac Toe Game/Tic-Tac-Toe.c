#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 3

int insert_position(char board[SIZE][SIZE]);
void output(char board[SIZE][SIZE]);
void input_name(char names[2][15]);
bool invalid_input(char board[SIZE][SIZE], int input);
bool decision(char board[SIZE][SIZE]);
void clear_screen();
void file_handling();

int main()
{
    printf("\nThis is TIC TAC TOE!\n\n");
    int num;
    int play_again;
    char board[SIZE][SIZE];
    char names[2][15];
    char symbol1;
    char symbol2;
    bool is_win;
    int input;
    int total_game = 0;
    int first_player_win_count = 0;
    int second_player_win_count = 0;
    int draw_count = 0;
    int first_player_lose_count;
    int second_player_lose_count;

    printf("press 1 for start game, 2 for view scores, 0 for stop game.");
    scanf("%d", &num);
    if (num == 1)
    {
        // Player name & Symbol
        input_name(names);
        printf("\n%s choose your symbol either X or O: ", names[0]);
        fflush(stdin);
        scanf("%c", &symbol1);

        symbol2 = symbol1 == 'X' ? 'O' : 'X';

        while (true)
        {
            // start with empty board
            for (int row = 0; row < SIZE; row++)
            {
                for (int col = 0; col < SIZE; col++)
                {
                    board[row][col] = ' ';
                }
            }

            printf("\nLet's start the game!\n\n");
            output(board);

            for (int k = 1; k <= (SIZE * SIZE); k++)
            {
                int row, col, turn;
                turn = k % 2 == 0 ? 1 : 0;

                printf("%s's turn:\n", names[turn]);

                input = insert_position(board);

                row = (input - 1) / SIZE;
                col = (input - 1) % SIZE;

                board[row][col] = turn == 0 ? symbol1 : symbol2;
                clear_screen();
                output(board);

                is_win = decision(board);
                if (is_win == true)
                {
                    printf("CONGRATULATIONS!\n%s you have WON the GAME!\n", names[turn]);
                    printf("GAME END!\n");

                    if (names[turn] == names[0])
                    {
                        first_player_win_count++;
                    }
                    else
                    {
                        second_player_win_count++;
                    }

                    break;
                }

                // Game Draw
                if (k == (SIZE * SIZE))
                {
                    printf("GAME DRAW!\n");
                    printf("GAME END!\n");
                    draw_count++;

                    break;
                }
            }
            // Score Box
            total_game = first_player_win_count + second_player_win_count + draw_count;
            first_player_lose_count = total_game - (first_player_win_count + draw_count);
            second_player_lose_count = total_game - (second_player_win_count + draw_count);
            printf("\nTotal Game = %d", total_game);
            printf("\n%s score = %d\n", names[0], first_player_win_count);
            printf("%s score = %d\n", names[1], second_player_win_count);
            printf("No. of Draw Games = %d\n", draw_count);

            // play again
            printf("\nDo you want to play again?\nPress 1 for YES and 0 for NO. ");
            scanf("%d", &play_again);

            if (play_again != 1)
            {
                break;
            }
        }
        FILE *fp;
        fp = fopen("char-copy.txt", "w");

        fprintf(fp, "Name:%s\n", names[0]);
        fprintf(fp, "Total_Game=%d\n", total_game);
        fprintf(fp, "Wins=%d \n", first_player_win_count);
        fprintf(fp, "Lose=%d \n", first_player_lose_count);

        fprintf(fp, "\nName:%s\n", names[1]);
        fprintf(fp, "Total_Game=%d\n", total_game);
        fprintf(fp, "Wins=%d \n", second_player_win_count);
        fprintf(fp, "Lose=%d \n", second_player_lose_count);

        fclose(fp);
    }
    if (num == 2)
    {
        int count = 2;
        char players[count][20];
        char total_games[count][20];
        char wins[count][20];
        char loses[count][20];
        char draws[count][20];

        FILE *fp;
        fp = fopen("char-copy.txt", "r");
        if (fp == NULL)
        {
            printf("Failed to create the file.\n");
        }
        char c, s;

        // fscanf(fp, "%d", &count);
        // printf("%d", count);

        for (int i = 0; i < count; i++)
        {
            fscanf(fp, "%s", &players[i]);
            fscanf(fp, "%s", &total_games[i]);
            fscanf(fp, "%s", &wins[i]);
            fscanf(fp, "%s", &loses[i]);

            printf("%s\n", players[i]);
            printf("%s\n", total_games[i]);
            printf("%s\n", wins[i]);
            printf("%s\n\n", loses[i]);

            // fscanf(fp, "%d", &draws[i]);
        }
        fclose(fp);
    }
    if (num == 0)
    {
        return 0;
    }

    // fscanf(fp, "Total Game = %d", &total_game);
    // fprintf(fp, "\nTotal Game = %d", total_game);
    // fscanf(fp, "Name: %s \nScore=%d ", &names[0], &first_player_win_count);
    // fprintf(fp, "\nName: %s \nScore=%d \n", names[0], first_player_win_count);
    // fscanf(fp, "Name: %s Score=%d ", &names[1], &second_player_win_count);
    // fprintf(fp, "\nName: %s \nScore=%d \n", names[1], second_player_win_count);
    // fscanf(fp, "No. of Draw Games = %d", &draw_count);
    // fprintf(fp, "No. of Draw Games = %d\n", draw_count);

    return 0;
}

void output(char board[SIZE][SIZE])
{
    printf("\n\n");

    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 0; col < SIZE; col++)
        {
            printf(" %c ", board[row][col]);

            if (col < (SIZE - 1))
            {
                printf("|", board[row][col]);
            }
        }

        printf("\n");

        if (row < (SIZE - 1))
        {
            for (int i = 0; i < SIZE; i++)
            {
                printf("----");
            }
            printf("\n");
        }
        else
        {
            printf(" ");
        }
    }

    printf("\n\n");
}

int insert_position(char board[SIZE][SIZE])
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

void clear_screen()
{
    system("cls");
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

bool invalid_input(char board[SIZE][SIZE], int input)
{
    int row, col;
    row = (input - 1) / SIZE;
    col = (input - 1) % SIZE;

    while (board[row][col] != ' ')
    {
        if (input > 0 && input < ((SIZE * SIZE) + 1))
        {
            printf("Repeated Input!\n");
        }

        if (input == 0 || input > ((SIZE * SIZE) + 1))
        {
            printf("Invalid Input\n");
        }
        return true;
    }

    return false;
}

bool decision(char board[SIZE][SIZE])
{
    //rows verification
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 1; col < SIZE; col++)
        {
            if ((board[row][col] != board[row][col - 1]) || (board[row][col] == ' '))
            {
                break;
            }

            if (col == (SIZE - 1))
            {
                return true;
            }
        }
    }

    //column verification
    for (int row = 0; row < SIZE; row++)
    {
        for (int col = 1; col < SIZE; col++)
        {
            if ((board[col][row] != board[col - 1][row]) || (board[col][row] == ' '))
            {
                break;
            }

            if (col == (SIZE - 1))
            {
                return true;
            }
        }
    }

    // Daigonal verification
    for (int row = 1; row < SIZE; row++)
    {
        if ((board[row][row] != board[row - 1][row - 1]) || (board[row][row] == ' '))
        {
            break;
        }

        if (row == (SIZE - 1))
        {
            return true;
        }
    }

    //Diagonal 2
    int row = 0;
    for (int col = (SIZE - 1); col >= 0; col--)
    {
        if ((board[row + 1][(SIZE - 1) - (row + 1)] != board[row][col]) || (board[row][col] == ' '))
        {
            break;
        }

        if (row == (SIZE - 2))
        {
            return true;
        }
        row = row + 1;
    }

    return false;
}
// void file_handling()
// {    char names[2][15];
//       int total_game = 0;
//     int first_player_win_count = 0;
//     int second_player_win_count = 0;
//     int draw_count = 0;

//         FILE *fp;
//     fp = fopen("char-copy.txt", "r");
//     fscanf(fp, "Total Game = %d", &total_game);
//     fprintf(fp, "\nTotal Game = %d", total_game);
//     fscanf(fp, "Name: %s \nScore=%d ", &names[0], &first_player_win_count);
//     fprintf(fp, "\nName: %s \nScore=%d \n", names[0], first_player_win_count);
//     fscanf(fp, "Name: %s Score=%d ", &names[1], &second_player_win_count);
//     fprintf(fp, "\nName: %s \nScore=%d \n", names[1], second_player_win_count);
//     fscanf(fp, "No. of Draw Games = %d", &draw_count);
//     fprintf(fp, "No. of Draw Games = %d\n", draw_count);

//     fclose(fp);}