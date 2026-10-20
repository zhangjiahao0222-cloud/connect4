#include <stdio.h>
#include <string.h>
#include "../Other/common.h"

char rank_name[20][20];
int  rank_score[20];
int  rank_count = 0;

void add_score(char player_name[], int points)
{
    int i;
    for (i = 0; i < rank_count; i++) {
        if (strcmp(rank_name[i], player_name) == 0) {
            rank_score[i] += points;
            return;
        }
    }
    if (rank_count < 20) {
        strcpy(rank_name[rank_count], player_name);
        rank_score[rank_count] = points;
        rank_count++;
    }
}

void show_ranking(void)
{
    int i, j, tmp;
    char tmp_name[20];

    for (i = 0; i < rank_count - 1; i++) {
        for (j = 0; j < rank_count - 1 - i; j++) {
            if (rank_score[j] < rank_score[j + 1]) {
                tmp = rank_score[j];
                rank_score[j] = rank_score[j + 1];
                rank_score[j + 1] = tmp;
                strcpy(tmp_name, rank_name[j]);
                strcpy(rank_name[j], rank_name[j + 1]);
                strcpy(rank_name[j + 1], tmp_name);
            }
        }
    }

    printf("\n===== RANKING =====\n");
    if (rank_count == 0)
        printf("No games yet.\n");
    for (i = 0; i < rank_count; i++)
        printf("%d. %-15s %d points\n", i + 1, rank_name[i], rank_score[i]);
}
