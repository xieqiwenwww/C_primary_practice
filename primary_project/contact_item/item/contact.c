#include "contact.h"

void InitContact(contact *pc)//初始化通讯录，把所有信息设置为0；
{
    pc->sz = 0;
    memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(contact *pc)
{
    if(MAX == pc->sz)
    {
        printf("通讯录已满，无法添加新联系人\n");
        return;
    }

    printf("请输入联系人的名字：");
    scanf("%s", pc->data[pc->sz].name);
    printf("请输入联系人的性别：");
    scanf("%s", pc->data[pc->sz].sex);
    printf("请输入联系人的年龄：");
    scanf("%d", &pc->data[pc->sz].age);
    printf("请输入联系人的电话：");
    scanf("%s", pc->data[pc->sz].tel);
    printf("请输入联系人的地址：");
    scanf("%s", pc->data[pc->sz].addr);

    pc->sz++;
    printf("联系人添加成功。\n");
}

void ContactPrint(const contact *pc)
{
    int i;
    printf("%-7s\t%-5s\t%-5s\t%-15s\t%-20s\n",
                "名字", "性别", "年龄", "电话", "地址");
    for(i = 0; i < pc->sz; i++)
    {
        printf("%-7s\t%-5s\t%-5d\t%-15s\t%-20s\n",
                                    pc->data[i].name,
                                    pc->data[i].sex,
                                    pc->data[i].age,
                                    pc->data[i].tel,
                                    pc->data[i].tel     );
    }
}


static int FineByName(contact *pc, char name[])
{
    int i;
    for(i = 0; i < pc->sz; i++)
    {
        if(0 == strcmp(pc->data[i].name, name))
        {
            return i;
        }
    }
    return -1;
}

void DelContact(contact *pc)
{
    char name[MAX_NAME];
    printf("请输入需要删除的联系人名字：");
    scanf("%s", name);
    if(0 == pc->sz)
    {
        printf("通讯录列表为空，无需删除。\n");
        return;
    }
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("通讯录中没有该联系人。\n");
        return;
    }
    int i;
    for(i = NameRet; i < pc->sz-1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->sz--;
    printf("删除成功。\n");
}

void SreachContact(contact *pc)
{
    char name[MAX_NAME];
    printf("请输入需要查找的联系人名字：");
    scanf("%s", name);
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("通讯录中没有该联系人。\n");
        return;
    }
    else
    {
        printf("%-7s\t%-5s\t%-5s\t%-15s\t%-20s\n",
                    "名字", "性别", "年龄", "电话", "地址");
        printf("%-7s\t%-5s\t%-5d\t%-15s\t%-20s\n",
                                        pc->data[NameRet].name,
                                        pc->data[NameRet].sex,
                                        pc->data[NameRet].age,
                                        pc->data[NameRet].tel,
                                        pc->data[NameRet].tel     );
    }
}


void ModifyContact(contact *pc)
{
    char name[MAX_NAME];
    printf("请输入需要修改的联系人名字：");
    scanf("%s", name);
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("通讯录中没有该联系人。\n");
        return;
    }
    else
    {
        printf("请输入联系人的名字：");
        scanf("%s", pc->data[NameRet].name);
        printf("请输入联系人的性别：");
        scanf("%s", pc->data[NameRet].sex);
        printf("请输入联系人的年龄：");
        scanf("%d", &pc->data[NameRet].age);
        printf("请输入联系人的电话：");
        scanf("%s", pc->data[NameRet].tel);
        printf("请输入联系人的地址：");
        scanf("%s", pc->data[NameRet].addr);
        printf("修改成功。\n");
    }
}

