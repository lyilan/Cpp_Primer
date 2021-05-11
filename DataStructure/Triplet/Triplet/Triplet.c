//
//  Triplet.c
//  Triplet
//
//  Created by Lyilan on 2021/4/24.
//

#include "Triplet.h"

// - - - - - 三元组函数的实现 - - - - -

Status InitTriplet(pTri *T, ElemType v1, ElemType v2, ElemType v3)
{
    //初始化三元组
    *T = (pTri)malloc(sizeof(Tri));
    if(*T==NULL)
        exit(OVERFLOW);//存储分配失败
    (*T)->e1 = v1;
    (*T)->e2 = v2;
    (*T)->e3 = v3;
    return OK;
}

Status DestroyTriplet(pTri *T)
{
    //销毁三元组
    if(*T == NULL)
        return ERROR;
    free(*T);
    *T = NULL;//指针指向NULL
    return OK;
}

Status Get(Tri T, int i, ElemType *e)
{
    //用e获取T中第i个元素
    switch (i) {
        case 1:
            *e = T.e1;
            break;
        case 2:
            *e = T.e2;
            break;
        case 3:
            *e = T.e3;
            break;
        default:
            return ERROR;
    }
    return OK;
}

Status Put(pTri T, int i, ElemType e)
{
    //将T中第i个元素置为e
    if(T == NULL)
        return ERROR;
    switch (i) {
        case 1:
            T->e1 = e;
            break;
        case 2:
            T->e2 = e;
            break;
        case 3:
            T->e3 = e;
            break;
        default:
            return ERROR;
    }
    return OK;
}

Status IsAscending(Tri T)
{
    //判断T中元素是否升序排列
    if(T.e1 <= T.e2 && T.e2 <= T.e3)
        return TRUE;
    else
        return FALSE;
}

Status IsDescending(Tri T)
{
    //判断T中元素是否降序排列
    if(T.e1 >= T.e2 && T.e2 >= T.e3)
        return TRUE;
    else
        return FALSE;
}

Status Max(Tri T, ElemType *e)
{
    //用e返回T中最大值
    if(T.e1 >= T.e2 && T.e1 >= T.e3)
        *e = T.e1;
    else if(T.e2 >= T.e3)
        *e = T.e2;
    else
        *e = T.e3;
    return OK;
}

Status Min(Tri T, ElemType *e)
{
    //用e返回T中最小值
    if(T.e1 <= T.e2 && T.e1 <= T.e3)
        *e = T.e1;
    else if(T.e2 <= T.e3)
        *e = T.e2;
    else
        *e = T.e3;
    return OK;
}
