#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TEL 12
#define MAX_ADDR 30

#define MAX 1000

#define DEDAULT_SZ 3
#define INC_SZ 2

typedef struct PeoInof
{
    char name[MAX_NAME];
    char sex[MAX_SEX];
    int age;
    char tel[MAX_TEL];
    char addr[MAX_ADDR];
}PeoInof;

// typedef struct contact//��̬�ڴ�
// {
//     PeoInof data[MAX];
//     int sz;
// }contact;

typedef struct contact//��̬�ڴ�
{
    PeoInof *data;
    int sz;
    int capacity;
}contact;


void InitContact(contact *pc);
void AddContact(contact *pc);
void ContactPrint(const contact *pc);
void DelContact(contact *pc);
void SreachContact(contact *pc);
void ModifyContact(contact *pc);
void FreeContact(contact *pc);
