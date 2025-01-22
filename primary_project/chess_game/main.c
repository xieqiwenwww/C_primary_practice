#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
//思路：游戏可以一直玩直到选择跳出，输出棋盘并初始化棋盘，玩家下棋与电脑下棋后判断输赢，
//返回结果玩家选择菜单

void menu()//游戏菜单选择
{
    printf("******************************\n");
    printf("*****       1.play      ******\n");
    printf("*****       0.exit      ******\n");
    printf("******************************\n");
}

void play_game()
{
    // printf("test\n");
    char board [ROW][COL];
    //初始化棋盘
    Init_Board(board, ROW, COL);
    //打印棋盘本质是打印数组
    Display_board(board, ROW, COL);
    char ret = 0;
    while(1)
    {
        player_move(board, ROW, COL);//玩家走
        Display_board(board, ROW, COL);
        ret = win_judge(board, ROW, COL);//判断输赢
        if(ret != 'C')
        {
            break;
        }
        
        computer_move(board, ROW, COL);//电脑走
        Display_board(board, ROW, COL);
        ret = win_judge(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
    }
    if(ret == '*')  //打印输赢最后结果
    {
        printf("player win\n");
    }
    else if(ret == '#')
    {
        printf("computer win\n");
    }
    else
    {
        printf("nobody win\n");
    }
    Display_board(board, ROW, COL);
}

int main ()
{
    int input;
    srand((unsigned int)time(NULL));
    do{
        menu();                     //菜单打印
        printf("Please select:");
        scanf("%d", &input);        //选择菜单
        switch(input)
        {
            case 1:
            {
                printf("chess game will start\n");
                play_game();        //进行游戏
                break;
            }
            case 0:                 //退出游戏
            {
                printf("exit game\n");
                break;
            }
            default:               //输入不匹配
            {
                printf("import error,please enter again\n");
                break;
            }
        }
    }while(input);
    system ("pause");
}