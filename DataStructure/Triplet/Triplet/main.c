//
//  main.c
//  Triplet
//
//  Created by Lyilan on 2021/4/24.
//

#include <stdio.h>
#include "Triplet.h"

int main(int argc, const char * argv[]) {
    pTri T = NULL;
    ElemType e = 0;
    
    //测试初始化函数
    if(InitTriplet(&T, 1, 2, 3))
    {
        printf("三元组T初始化成功！\n");
    }
    else
    {
        printf("三元组T初始化失败！\n");
    }
    
    //测试Get函数
    for(int i = 1; i <= 3; i++)
    {
        Get(*T, i, &e);
        printf("T的第%d个元素是%d\n",i,e);
    }
    
    //测试Put函数
    Put(T, 3, 5);
    if(T->e3 == 5)
    {
        printf("3号元素赋值成功\n");
    }
    else
    {
        printf("3号元素赋值失败\n");
    }
    
    //测试升序判断函数
    if(IsAscending(*T))
    {
        printf("T为升序排列\n");
    }
    else
    {
        printf("T不为升序排列\n");
    }
    
    //测试降序判断函数
    if(IsDescending(*T))
    {
        printf("T为降序排列\n");
    }
    else
    {
        printf("T不为降序排列\n");
    }
    
    //测试最大值函数
    Max(*T, &e);
    printf("T中最大值为%d\n",e);
    
    //测试最小值函数
    Min(*T, &e);
    printf("T中最小值为%d\n",e);
    
    //测试销毁函数
    if(DestroyTriplet(&T))
    {
        printf("三元组销毁成功！\n");
    }
    else
    {
        printf("三元组销毁失败！\n");
    }
    return 0;
}
