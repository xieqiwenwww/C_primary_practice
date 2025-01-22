#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game.h"
//˼·����Ϸ����һֱ��ֱ��ѡ��������������̲���ʼ�����̣�������������������ж���Ӯ��
//���ؽ�����ѡ��˵�

void menu()//��Ϸ�˵�ѡ��
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
    //��ʼ������
    Init_Board(board, ROW, COL);
    //��ӡ���̱����Ǵ�ӡ����
    Display_board(board, ROW, COL);
    char ret = 0;
    while(1)
    {
        player_move(board, ROW, COL);//�����
        Display_board(board, ROW, COL);
        ret = win_judge(board, ROW, COL);//�ж���Ӯ
        if(ret != 'C')
        {
            break;
        }
        
        computer_move(board, ROW, COL);//������
        Display_board(board, ROW, COL);
        ret = win_judge(board, ROW, COL);
        if(ret != 'C')
        {
            break;
        }
    }
    if(ret == '*')  //��ӡ��Ӯ�����
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
        menu();                     //�˵���ӡ
        printf("Please select:");
        scanf("%d", &input);        //ѡ��˵�
        switch(input)
        {
            case 1:
            {
                printf("chess game will start\n");
                play_game();        //������Ϸ
                break;
            }
            case 0:                 //�˳���Ϸ
            {
                printf("exit game\n");
                break;
            }
            default:               //���벻ƥ��
            {
                printf("import error,please enter again\n");
                break;
            }
        }
    }while(input);
    system ("pause");
}