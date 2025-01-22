#include "game.h"

void Init_board(char board[ROW][COL], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            board[i][j] = ' ';
        }
    }
}

void Print_board(char board[ROW][COL], int row, int col)
{
    int i;
    for(i = 0; i < row; i++)
    {
        int j;
        for(j = 0; j < col; j++)
        {
            printf(" %c ", board[i][j]);
            if(j < col - 1)
            {
                printf("|");
            }
        }
        printf("\n");
        if(i < row -1)
        {
            for(j = 0; j < col; j++)
            {
                printf("---");
                if(j < col -1)
                {
                    printf("|");
                }
            }
        }
        printf("\n");
    }
}

void player_move(char board[ROW][COL], int row, int col)
{
    int x, y;
    while(1)
    {
        printf("请输入您的坐标：");
        scanf("%d %d", &x, &y);
        if(x-1 >= 0 && x <= row && y-1 >= 0 && y <= col )//判断输入坐标是否合法
        {
            if(board[x-1][y-1] == ' ')
            {
                board[x-1][y-1] = '*';
                break;
            }
            else{
                printf("坐标已被占用，请重新输入\n");
            }
            // int i, j;
            // for(i = 0; i < row; i++)
            // {
            //     for(j = 0; j < col; j++)
            //     {
            //         if(board[i][j])
            //     }
            // }
        }
        else{
            printf("输入坐标不合法，请重新输入\n");
        }
    }
}

void computer_move(char board[ROW][COL], int row, int col)
{
    printf("电脑输入\n");
    while(1)
    {
        int x = rand()%row;
        int y = rand()%col;
        if(board[x][y] == ' ')
        {
            board[x][y] = '#';
            break;
        }
    }
}

int full(char board[ROW][COL], int row, int col)
{
    int i, j;
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(board[i][j] == ' ')
            {
                return 0;
            }
        }
    }
    return 1;
}


char WIN_judge(char board[ROW][COL], int row, int col)
{
    char ret;
    int i, j;
    for(i = 0; i < row; i++)
    {
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ')
        {
            return board[i][0];
        }
    }

    for(i = 0; i < col; i++)
    {
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[2][i] != ' ')
        {
           return board[i][0];
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[3][2] && board[0][0] != ' ')
    {
       return board[0][0];
    }

    if(board[0][3] == board[1][1] && board[1][1] == board[3][0] && board[1][1] != ' ')
    {
       return board[0][0];
    }

    int tempt = full(board, row, col);
    if(tempt == 1)
    {
        ret = 'Q';
        return ret;
    }
     return 'C';
    
}

