//
//  main.c
//  SqList
//
//  Created by Lyilan on 2021/4/28.
//

#include <stdio.h>
#include "SqList.h"

int main(int argc, const char * argv[]) {
    SqList L;
    
    //测试初始化函数
    if(InitList(&L))
        printf("线性表初始化成功！\n");
    else
        printf("存储分配失败，堆栈已满！\n");
    
    //测试插入函数
    for(int i = 1; i < 21; i++)
        if(!ListInsert(&L, i, i * i))
            printf("插入失败！\n");
    
    //测试遍历函数
    if(ListTraverse(L, PrintElem))
        printf("\n线性表遍历成功！\n");
    
    //测试ListLength
    printf("线性表长度为 %d !\n", ListLength(L));
    
    //测试GetElem
    for(int i = 1; i < 22; i++)
    {
        ElemType e = 0;
        if(GetElem(L, i, &e))
            printf("第%d个元素是%d\n", i, e);
        else
            printf("查找失败！\n");
    }
    
    //测试查找函数
    int Pos;
    for(int i = 23; i > 0 ; i--)
        if((Pos = LocateElem(L, i * i, IsEqual)))
            printf("%4d在第%2d位上\n", i * i, Pos);
        else
            printf("%4d不存在！\n", i * i);
    
    //测试删除函数
    for(int i = 11; i < 22; i++)
    {
        ElemType e;
        if(ListDelete(&L, i, &e))
            printf("第%2d号元素%4d删除成功\n", i, e);
        else
            printf("删除失败，检查删除位置！\n");
    }
    
    //测试清空函数
    if(ClearList(&L))
        printf("线性表清空成功！\n");
    else
        printf("线性表清空失败！\n");
    
    //测试ListEmpty
    if(ListEmpty(L))
        printf("线性表为空\n");
    else
        printf("线性表不为空\n");
    
    //测试销毁函数
    if(DestroyList(&L))
        printf("线性表销毁成功！\n");
    else
        printf("线性表销毁失败！\n");
    
    
    return 0;
}
