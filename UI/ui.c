#include <stdio.h>
#include <stdlib.h>
#include "../Other/common.h"

void show_menu(void)
{
    printf("\n===== CONNECT 4 =====\n");
    printf("1. Play\n");
    printf("2. Ranking\n");
    printf("3. Exit\n");
    printf("Choose: ");
}

void show_board(void)
{
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("|");
        for (j = 0; j < COLS; j++)
            printf(" %c |", board[i][j]);
        printf("\n");
    }
    printf("-----------------------------\n");
    printf("  1   2   3   4   5   6   7\n\n");
}

int read_number(void)
{
    int x, result, c;
    while (1) {
        result = scanf("%d", &x);
        if (result == 1)
            return x;
        if (result == EOF)
            exit(0);
        while ((c = getchar()) != '\n' && c != EOF)
            ;
        printf("Please enter a number: ");
    }
}

void read_name(char n[])
{
    int c;
    if (scanf("%19s", n) != 1)
        exit(0);
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int ask_column(int player)
{
    int col;
    while (1) {
        printf("%s (%c), choose column 1-7: ", name[player], player == 0 ? 'O' : 'X');
        col = read_number();
        if (col < 1 || col > COLS)
            printf("Column must be 1-7.\n");
        else if (board[0][col - 1] != ' ')
            printf("This column is full.\n");
        else
            return col - 1;
    }
}
