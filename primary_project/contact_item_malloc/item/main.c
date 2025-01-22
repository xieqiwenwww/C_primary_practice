#include "contact.h"

void mnue()//菜单
{
    printf("************************************\n");
    printf("********   1.add     2.delet  ******\n");
    printf("********   3.sreach  4.modify ******\n");
    printf("********   5.sort    6.print  ******\n");
    printf("********   0.exit             ******\n");
    printf("************************************\n");
}
enum Option
{
    EXIT,
    ADD,
    DELET,
    SREACH,
    MODIFY,
    SORT,
    PRINT
};

int main ()
{
    int input;
    contact con;
    InitContact(&con);

    do
    {
        mnue();
        printf("请选择：");
        scanf("%d", &input);
        switch(input)
        {
            case ADD:
            {
                AddContact(&con);
                break;
            }
            case DELET:
            {
                DelContact(&con);
                break;
            }
            case SREACH:
            {
                SreachContact(&con);
                break;
            }
            case MODIFY:
            {
                ModifyContact(&con);
                break;
            }
            case SORT:
            {
                break;
            }
            case PRINT:
            {
                ContactPrint(&con);
                break;
            }
            case EXIT:
            {
                FreeContact(&con);
                break;
            }
            default:
            {
                printf("选择错误，请重新输入。\n");
                break;
            }
        }
    } while (input);

    system ("pause");
}
