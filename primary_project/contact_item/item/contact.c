#include "contact.h"

void InitContact(contact *pc)//��ʼ��ͨѶ¼����������Ϣ����Ϊ0��
{
    pc->sz = 0;
    memset(pc->data, 0, sizeof(pc->data));
}

void AddContact(contact *pc)
{
    if(MAX == pc->sz)
    {
        printf("ͨѶ¼�������޷��������ϵ��\n");
        return;
    }

    printf("��������ϵ�˵����֣�");
    scanf("%s", pc->data[pc->sz].name);
    printf("��������ϵ�˵��Ա�");
    scanf("%s", pc->data[pc->sz].sex);
    printf("��������ϵ�˵����䣺");
    scanf("%d", &pc->data[pc->sz].age);
    printf("��������ϵ�˵ĵ绰��");
    scanf("%s", pc->data[pc->sz].tel);
    printf("��������ϵ�˵ĵ�ַ��");
    scanf("%s", pc->data[pc->sz].addr);

    pc->sz++;
    printf("��ϵ����ӳɹ���\n");
}

void ContactPrint(const contact *pc)
{
    int i;
    printf("%-7s\t%-5s\t%-5s\t%-15s\t%-20s\n",
                "����", "�Ա�", "����", "�绰", "��ַ");
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
    printf("��������Ҫɾ������ϵ�����֣�");
    scanf("%s", name);
    if(0 == pc->sz)
    {
        printf("ͨѶ¼�б�Ϊ�գ�����ɾ����\n");
        return;
    }
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("ͨѶ¼��û�и���ϵ�ˡ�\n");
        return;
    }
    int i;
    for(i = NameRet; i < pc->sz-1; i++)
    {
        pc->data[i] = pc->data[i + 1];
    }
    pc->sz--;
    printf("ɾ���ɹ���\n");
}

void SreachContact(contact *pc)
{
    char name[MAX_NAME];
    printf("��������Ҫ���ҵ���ϵ�����֣�");
    scanf("%s", name);
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("ͨѶ¼��û�и���ϵ�ˡ�\n");
        return;
    }
    else
    {
        printf("%-7s\t%-5s\t%-5s\t%-15s\t%-20s\n",
                    "����", "�Ա�", "����", "�绰", "��ַ");
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
    printf("��������Ҫ�޸ĵ���ϵ�����֣�");
    scanf("%s", name);
    int NameRet = FineByName(pc, name);
    if(-1 == NameRet)
    {
        printf("ͨѶ¼��û�и���ϵ�ˡ�\n");
        return;
    }
    else
    {
        printf("��������ϵ�˵����֣�");
        scanf("%s", pc->data[NameRet].name);
        printf("��������ϵ�˵��Ա�");
        scanf("%s", pc->data[NameRet].sex);
        printf("��������ϵ�˵����䣺");
        scanf("%d", &pc->data[NameRet].age);
        printf("��������ϵ�˵ĵ绰��");
        scanf("%s", pc->data[NameRet].tel);
        printf("��������ϵ�˵ĵ�ַ��");
        scanf("%s", pc->data[NameRet].addr);
        printf("�޸ĳɹ���\n");
    }
}

