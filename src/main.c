#include<stdio.h>
#include"SqList.h"

int main() {
    SqList l = InitSqList();
    int tri0 = 1;
    while (tri0) {
        int t0;
        printf("\n-------------------欢迎来到员工管理系统！-------------------\n");
        printf("当前系统人数：%d 当前系统容量：%d\n", l->len, l->size);
        printf("请选择您接下来要进行的操作：\n");
        printf("1. 在指定位置新建员工信息；\n");
        printf("2. 删除员工信息：\n");
        printf("3. 显示员工信息：\n");
        printf("4. 退出；\n");
        scanf("%d", &t0);
        switch(t0) {
            case 1 : {
                employee e;
                printf("请按格式输入：工号 姓名 所在部门 职务\n");
                printf("注意：工号须为8位且唯一；姓名、部门、职务需满足：英文不超过100个字符，中文不超过50个汉字，包括“·”\n");
                printf("请输入：");
                int check1 = scanf("%d %s %s %s", &e.id, e.name, e.depart, e.posi);
                while (Locate(l, e.id) != -1 || !check1) {
                    if (!check1){
                        printf("输入格式错误！请重新输入：");
                        check1 = scanf("%d %s %s %s", &e.id, e.name, e.depart, e.posi);
                    }
                    else if (Locate(l, e.id) != -1){
                        printf("工号重复！请重新按上述格式输入学生信息：");
                        check1 = scanf("%d %s %s %s", &e.id, e.name, e.depart, e.posi);
                    }
                }
                printf("请输入插入位置：（当前系统人数为%d，输入请不要超过%d）", l->len, l->len + 1);
                int i;
                int check2 = scanf("%d", &i);
                while (!check2 || i < 1 || i > l->len + 1){ 
                    if (!check2){
                        printf("输入格式错误！请重新输入：");
                        check2 = scanf("%d", &i);
                    }
                    else if (i < 1){
                        printf("插入位置过小！请重新输入：");
                        check2 = scanf("%d", &i);
                    }
                    else if (i > l->len + 1){
                        printf("插入位置过大！请重新输入：");
                        check2 = scanf("%d", &i);
                    }
                }
                int t = InsertSqList(l, i, e);
                if (t == 1)
                    printf("插入成功！\n");
                else if(t == 0)
                    printf("系统空间不足！请稍后再试。\n");
                else if(t == -1)
                    printf("插入位置过小！请重新输入。\n");
                else if(t == -2)
                    printf("插入位置过大！请重新输入。\n");
                break;
            }
            case 2 : {
                int t1, tri = 1;
                while (tri) {
                    printf("请选择操作：\n");
                    printf("1. 按位置删除；\n");
                    printf("2. 按工号删除：\n");
                    printf("3. 返回：\n");
                    scanf("%d", &t1);
                    switch (t1) {
                        case 1 : {
                            int i;
                            printf("请输入删除员工的位置：");
                            int check = scanf("%d", &i);
                            while (!check || i < 1 || i > l->len + 1){ 
                                if (!check){
                                    printf("输入格式错误！请重新输入：");
                                    check = scanf("%d", &i);
                                }
                                else if (i < 1){
                                    printf("删除位置过小！请重新输入：");
                                    check = scanf("%d", &i);
                                }
                                else if (i > l->len + 1){
                                    printf("删除位置过大！请重新输入：");
                                    check = scanf("%d", &i);
                                }
                            }
                            employee e;
                            int t = Delete_i(l, i, &e);
                            if (t == 1){
                                printf("员工：%20d%20s%20s%20s\n", e.id, e.name, e.depart, e.posi);
                                printf("删除成功！\n");
                            }
                            else if(t == 0)
                                printf("系统为空，无法进行删除操作！\n");
                            else if(t == -1)
                                printf("删除位置过小！请重新输入。\n");
                            else if(t == -2)
                                printf("删除位置过大！请重新输入。\n");
                            break;
                        }
                        case 2 : {
                            int id;
                            printf("请输入删除员工的工号：");
                            int check = scanf("%d", &id);
                            while (!check || Locate(l, id) == -1){ 
                                if (!check){
                                    printf("输入格式错误！请重新输入：");
                                    check = scanf("%d", &id);
                                }
                                else {
                                    printf("工号不存在！请重新输入：");
                                    check = scanf("%d", &id);
                                }
                            }
                            employee e;
                            int t = Delete_id(l, id, &e);
                            if (t == 1){
                                printf("员工：%20d%20s%20s%20s\n", e.id, e.name, e.depart, e.posi);
                                printf("删除成功！\n");
                            }
                            else if(t == 0)
                                printf("系统为空，无法进行删除操作！\n");
                            else if(t == -1)
                                printf("删除位置过小！请重新输入。\n");
                            else if(t == -2)
                                printf("删除位置过大！请重新输入。\n");
                            break;
                        }
                        case 3 : {
                            tri = 0;
                            break;
                        }
                        default : {
                            printf("请输入1~3之间的数字：");
                            break;
                        }
                    }
                }
                break;
            }
            case 3 : {
                Show(l);
                break;
            }
            case 4 : {
                tri0 = 0;
                break;
            }
            default : {
                printf("请输入1~4之间的数字：");
                break;
            }
        }
    }
    return 0;
}