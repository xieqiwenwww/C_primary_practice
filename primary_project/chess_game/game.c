#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"

void Init_Board(char board[ROW][COL], int row, int col)//��ʼ������
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board [i][j] = ' ';
        }
    }
}

void Display_board(char board[ROW][COL], int row, int col)//��ӡ����
{
    int i;
    for(i = 0; i < row; i++)
    {
        int j = 0;
        for(j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i < row - 1)
        {
            int j = 0;
            for(j = 0; j < col; j++)
            {
                printf("---");
                if(j < col - 1)
                {
                    printf("|");
                }
            }
            printf("\n");
        }
    }
}

void player_move(char board[ROW][COL], int row, int col)
{
    int x, y;
    printf("player move:\n");
    while(1)
    {
        printf("Please enter the coordinate:");
        scanf("%d %d", &x, &y);
        if(x >= 1 && x <= row && y >=1 && y <= col)
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else 
            {
                printf("Please enter again.\n");
            }
        }
        else{
            printf("Please enter again.\n");
        }
    }
}

void computer_move(char board[ROW][COL], int row, int col)
{
    printf("computer move.\n");
    while(1)
    {
        int x = rand()%row; //���������
        int y = rand()%col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

//�ж������Ƿ��Ѿ�մ��
int ISfull(char board[ROW][COL], int row, int col)
{
    int i;
    for (i = 0; i < row; i++)
    {
        int j;
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
            {
                // printf("%d %d\n", i, j);
                return 0;
            }
        }
    }
    return 1;
}

/*
���Ӯ����'*'
����Ӯ����'#'
ƽ�ַ���'Q'
��Ϸ����'C'
*/
char win_judge(char board[ROW][COL], int row, int col)
{
    int i;
    for(i = 0; i < row; i++)//�ж���
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][1];
        }
    }

    for(i = 0; i < col; i++)//�ж���
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ')
        {
            return board[1][i];
        }
    } 

    //�Խ����ж���Ӯ
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ')
    {
        return board[1][1];
    }

    if(board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[0][0] != ' ')
    {
        return board[1][1];
    }

    //�ж��Ƿ�ƽ��
    int temporary = ISfull(board, row, col);
    if(temporary == 1)
    {
        return 'Q';
    }
    return 'C';
}
