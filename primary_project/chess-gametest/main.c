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
        printf("���Ӯ\n");
    }
    else if(key == '#')
    {
        printf("����Ӯ\n");
    }
    else{
        printf("ƽ��\n");
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
        printf("��ѡ��˵�:");
        scanf("%d", &input);
        switch(input)
        {
            case 1:
            {
                printf("��Ϸ������ʼ\n");
                my_game();
                break;
            }
            case 0:
            {
                printf("�˳���Ϸ\n");
                break;
            }
            default:
            {
                printf("�����������������\n");
                break;
            }
        }
    }while(input);
    system ("pause");
}
