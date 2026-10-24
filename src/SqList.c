#include"SqList.h"
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>

SqList InitSqList() {
    SqList l;
    l = (SqList)malloc(sizeof(SqList));
    if (!l->list)
        return NULL;
    else {
        l->len = 0;
        l->size = INIT_SIZE;
        employee * p = (employee *)malloc(sizeof(employee) * INIT_SIZE);
        if (!p)
            return NULL;
        l->list = p;
        return l;
    }
}

employee GetElm(SqList l, int i) { return l->list[i]; }

int Locate(SqList l, int id) {
    for (int i = 0; i < l->len; i ++)
        if (l->list[i].id == id)
            return i;
    return -1;
}

int InsertSqList(SqList l, int i, employee e) {
    if (i < 1)
        return -1;
    else if (i > l->len + 1)
        return -2;
    if (l->len >= l->size) {
        employee * p = (employee *)realloc(l->list, (DELTA + l->len)*sizeof(employee));
        if (!p)
            return 0;
        else {
            l->list = p;
            l->size += DELTA;
        }
    }
    for (int j = l->len; j >= i; j --)   
        l->list[j] = l->list[j-1];
    l->list[i-1] = e;
    l->len ++;
    return 1;
}

int Delete_i(SqList l, int i, employee *e) {
    if (i < 1)
        return -1;
    else if (i > l->len + 1)
        return -2;
    if (l->len == 0)
        return 0;
    *e = l->list[i-1]; 
    for (int j = i-1; j < l->len - 1; j ++)
        l->list[j] = l->list[j + 1];
    l->len --;
    return 1;
}

int Delete_id(SqList l, int id, employee *e) {
    int i = Locate(l, id);
    if (i == -1)
        return 0;
    else
        if (Delete_i(l, i+1, e))
            return 1;
}

void Show(SqList l) {
    printf("%25s%25s%25s%25s%25s\n", "序号", "工号", "姓名", "部门", "职位");
    if (l->len == 0){
        printf("(空)\n");
        return ;
    }
    for (int i = 0; i < l->len; i ++){
        employee e = l->list[i];
        printf("%25d%25d%25s%25s%25s\n", i+1, e.id, e.name, e.depart, e.posi);
    }
}

void search_id(SqList l, int id) {
    SqList result = InitSqList();
    for (int i = 0; i < l->len; i ++)
        if (l->list[i].id == id)
            InsertSqList(result, result->len + 1, l->list[i]);
    Show(result);
    free(result);
}

void search_name(SqList l, char *name) {
    SqList result = InitSqList();
    for (int i = 0; i < l->len; i ++)
        if (strcmp(l->list[i].name, name) == 0)
            InsertSqList(result, result->len + 1, l->list[i]);
    Show(result);
    free(result);
}

void search_posi(SqList l, char *posi) {
    SqList result = InitSqList();
    for (int i = 0; i < l->len; i ++)
        if (strcmp(l->list[i].posi, posi) == 0)
            InsertSqList(result, result->len + 1, l->list[i]);
    Show(result);
    free(result);
}

void search_depart(SqList l, char *depart) {
    SqList result = InitSqList();
    for (int i = 0; i < l->len; i ++)
        if (strcmp(l->list[i].depart, depart) == 0)
            InsertSqList(result, result->len + 1, l->list[i]);
    Show(result);
    free(result);
}