#ifndef  __GAME_H__
#define  __GAME_H__

#define ROW   3
#define COL   3

void Init_Board(char board[ROW][COL], int row, int col);
void Display_board(char board[ROW][COL], int row, int col);
void player_move(char board[ROW][COL], int row, int col);
void computer_move(char board[ROW][COL], int row, int col);

/*
���Ӯ����'*'
����Ӯ����'#'
ƽ�ַ���'Q'
��Ϸ��������'C'
*/
char win_judge(char board[ROW][COL], int row, int col);


#endif
