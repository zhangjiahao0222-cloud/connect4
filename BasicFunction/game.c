/* Part 2: Basic Function - the board, placing pieces, judging the winner */
#include "../Other/common.h"

char board[ROWS][COLS];

void clear_board(void)
{
    int i, j;
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS; j++)
            board[i][j] = ' ';
}

/* Exercise 3: the piece falls to the lowest empty cell of the column */
void drop_piece(int col, char piece)
{
    int i;
    for (i = ROWS - 1; i >= 0; i--) {
        if (board[i][col] == ' ') {
            board[i][col] = piece;
            return;
        }
    }
}

int check_win(char piece)
{
    int i, j;

    /* Exercise 1: horizontal */
    for (i = 0; i < ROWS; i++)
        for (j = 0; j < COLS - 3; j++)
            if (board[i][j] == piece && board[i][j+1] == piece &&
                board[i][j+2] == piece && board[i][j+3] == piece)
                return 1;

    /* Exercise 1: vertical */
    for (i = 0; i < ROWS - 3; i++)
        for (j = 0; j < COLS; j++)
            if (board[i][j] == piece && board[i+1][j] == piece &&
                board[i+2][j] == piece && board[i+3][j] == piece)
                return 1;

    /* Exercise 2: diagonal \ */
    for (i = 0; i < ROWS - 3; i++)
        for (j = 0; j < COLS - 3; j++)
            if (board[i][j] == piece && board[i+1][j+1] == piece &&
                board[i+2][j+2] == piece && board[i+3][j+3] == piece)
                return 1;

    /* Exercise 2: diagonal / */
    for (i = 0; i < ROWS - 3; i++)
        for (j = 3; j < COLS; j++)
            if (board[i][j] == piece && board[i+1][j-1] == piece &&
                board[i+2][j-2] == piece && board[i+3][j-3] == piece)
                return 1;

    return 0;
}

/* the board is full when the top row has no empty cell */
int board_full(void)
{
    int j;
    for (j = 0; j < COLS; j++)
        if (board[0][j] == ' ')
            return 0;
    return 1;
}
