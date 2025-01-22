#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROW     3
#define COL     3

void Init_board(char board[ROW][COL], int row, int col);
void Print_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);
char WIN_judge(char board[ROW][COL], int row, int col);
