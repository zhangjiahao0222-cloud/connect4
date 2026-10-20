/* common.h - shared by all four parts */
#ifndef COMMON_H
#define COMMON_H

#define ROWS 6
#define COLS 7

/* board[0] is the top row, board[5] is the bottom row */
extern char board[ROWS][COLS];   /* defined in BasicFunction/game.c */
extern char name[2][20];         /* defined in Other/main.c */

/* Part 1: UI */
void show_menu(void);
void show_board(void);
int  read_number(void);
void read_name(char n[]);
int  ask_column(int player);

/* Part 2: Basic Function */
void clear_board(void);
void drop_piece(int col, char piece);
int  check_win(char piece);
int  board_full(void);

/* Part 3: Score Ranking */
void add_score(char player_name[], int points);
void show_ranking(void);

#endif
