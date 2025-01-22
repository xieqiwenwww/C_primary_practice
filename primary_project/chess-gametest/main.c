#include "game.h"

void menu()
{
    printf("*****************************\n");
    printf("********    1.play    *******\n");
    printf("********    0.exit    *******\n");
    printf("*****************************\n");
}


void my_game()
{
    char board[ROW][COL];
    Init_board(board, ROW, COL);
    Print_board(board, ROW, COL);
    char key;
    while(1)
    {
        player_move(board, ROW, COL);
        key = WIN_judge(board, ROW, COL);
        if(key != 'C')
        {
            break;
        }
        Print_board(board, ROW, COL);

        computer_move(board, ROW, COL);
        key = WIN_judge(board, ROW, COL);
        if(key != 'C')
        {
            break;
        }
        Print_board(board, ROW, COL);
    }
    if(key == '*')
    {
        printf("玩家赢\n");
    }
    else if(key == '#')
    {
        printf("电脑赢\n");
    }
    else{
        printf("平局\n");
    }
    Print_board(board, ROW, COL);
}

int main()
{
    int input;
    srand((unsigned int)time(NULL));
    do
    {
        menu();
        printf("请选择菜单:");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            {
                printf("游戏即将开始\n");
                my_game();
                break;
            }
            case 0:
            {
                printf("退出游戏\n");
                break;
            }
            default:
            {
                printf("输入错误请重新输入\n");
                break;
            }
        }
    }while(input);
    system ("pause");
}
