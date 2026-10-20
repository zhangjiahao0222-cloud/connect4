#ifndef COMMON_H
#define COMMON_H

#define ROWS 6
#define COLS 7

extern char board[ROWS][COLS];
extern char name[2][20];

void show_menu(void);
void show_board(void);
int  read_number(void);
void read_name(char n[]);
int  ask_column(int player);

void clear_board(void);
void drop_piece(int col, char piece);
int  check_win(char piece);
int  board_full(void);

void add_score(char player_name[], int points);
void show_ranking(void);

#endif
