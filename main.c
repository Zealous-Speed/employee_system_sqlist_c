#include<stdio.h>
#include"SqList.h"

int main() {
    SqList l = InitSqList();
    employee e;
    scanf("%d %s %s %s", &e.id, e.name, e.depart, e.posi);
    InsertSqList(l, 1, e);
    Show(l);
    return 0;
}