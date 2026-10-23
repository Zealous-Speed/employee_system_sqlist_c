#include"employee.h"
#ifndef _SQLIST
#define _SQLIST
#define INIT_SIZE 1
#define DELTA 10

typedef struct {
    int len, size;
    employee *list;
} *SqList;

SqList InitSqList();
employee GetElm(SqList l, int i);
int Locate(SqList l, int id);
int InsertSqList(SqList l, int i, employee e);
int Delete_i(SqList l, int i, employee *e);
int Delete_id(SqList l, int id, employee *e);
void Show(SqList l);
void search_id(SqList l, int id);
void search_name(SqList l, char *name);
void search_posi(SqList l, char *posi);
void search_depart(SqList l, char *depart);

#endif