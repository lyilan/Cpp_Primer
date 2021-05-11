//
//  SqList.c
//  SqList
//
//  Created by Lyilan on 2021/4/28.
//

#include "SqList.h"
#include <stdlib.h>

// - - - - - 线性表基本操作函数的实现 - - - - -
Status InitList(SqList *L)
{
    //构造一个空的线性表
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem)
        exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
    return OK;
}

Status DestroyList(SqList *L)
{
    //销毁线性表
    if(L == NULL || L->elem == NULL)
        return ERROR;
    free(L->elem);
    L->elem = NULL;
    L->length = 0;
    return OK;
}

Status ClearList(SqList *L)
{
    //清空线性表
    if(L == NULL || L->elem == NULL)
        return ERROR;
    L->length = 0;
    return OK;
}

Status ListEmpty(SqList L)
{
    //判断线性表是否为空
    return L.length ? FALSE : TRUE;
}

int ListLength(SqList L)
{
    //求线性表中元素个数
    return L.length;
}

Status GetElem(SqList L, int i, ElemType *e)
{
    //用e返回L中第i个元素的值
    if(i < 1 || i > L.length)
        return ERROR;
    *e = L.elem[i-1];
    return OK;
}

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType))
{
    //找到线性表中一个与e满足compare()元素的位置
    for(int i = 0; i < L.length; i++)
        if(compare(L.elem[i],e))
            return i + 1;
    return 0;
}

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e)
{
    //寻找前驱元素
    int i = LocateElem(L, cur_e, IsEqual);
    if(i > 1)
        *pre_e = L.elem[i - 2];
    else
        return ERROR;
    return OK;
}

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e)
{
    //寻找后继元素
    int i = LocateElem(L, cur_e, IsEqual);
    if(i > 0 && i < L.length)
        *next_e = L.elem[i - 1];
    else
        return ERROR;
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    //插入元素
    if(i < 1 || i > L->length + 1)
        return ERROR;
    if(L->length >= L->listsize)
    {
        ElemType * newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase)
            return ERROR;
        L->elem = newbase;
        L->listsize += LISTINCREMENT;
    }
    for(int j = L->length; j >= i; j--)
        L->elem[j] = L->elem[j - 1];
    L->elem[i - 1] = e;
    L->length++;
    return OK;
}

Status ListDelete(SqList *L, int i, ElemType *e)
{
    //删除元素
    if(i < 1 || i > L->length)
        return ERROR;
    *e = L->elem[i - 1];
    for(int j = i - 1; j < L->length - 2; j++)
        L->elem[j] = L->elem[j + 1];
    L->length--;
    return OK;
}

Status ListTraverse(SqList L, Status(*visit)(ElemType))
{
    for(int i = 0; i < L.length; i++)
        if(!visit(L.elem[i]))
            return ERROR;
    return OK;
}

// - - - - - 内部函数的实现 - - - - -
Status IsEqual(ElemType e1, ElemType e2)
{
    return e1 == e2 ? TRUE : FALSE;
}

Status PrintElem(ElemType e)
{
    printf("%d ", e);
    return OK;
}
