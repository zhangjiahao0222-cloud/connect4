/* Part 4: Other - main menu and the game loop (Exercise 4) */
#include <stdio.h>
#include <string.h>
#include "common.h"

char name[2][20];

void play_game(void)
{
    int player = 0;
    int col;
    char piece;

    printf("Player 1 name (O): ");
    read_name(name[0]);
    printf("Player 2 name (X): ");
    read_name(name[1]);
    while (strcmp(name[0], name[1]) == 0) {
        printf("Use a different name: ");
        read_name(name[1]);
    }

    clear_board();
    while (1) {
        show_board();
        col = ask_column(player);
        piece = (player == 0) ? 'O' : 'X';
        drop_piece(col, piece);

        if (check_win(piece)) {
            show_board();
            printf("%s wins!\n", name[player]);
            add_score(name[player], 3);
            add_score(name[1 - player], 0);
            return;
        }
        if (board_full()) {
            show_board();
            printf("Draw!\n");
            add_score(name[0], 1);
            add_score(name[1], 1);
            return;
        }
        player = 1 - player;
    }
}

int main(void)
{
    int choice;
    while (1) {
        show_menu();
        choice = read_number();
        if (choice == 1)
            play_game();
        else if (choice == 2)
            show_ranking();
        else if (choice == 3)
            break;
        else
            printf("Please choose 1, 2 or 3.\n");
    }
    printf("Bye!\n");
    return 0;
}
