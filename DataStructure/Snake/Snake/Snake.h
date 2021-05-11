//
//  Snake.h
//  Snake
//
//  Created by Lyilan on 2021/4/24.
//

#ifndef Snake_h
#define Snake_h

#include <stdio.h>
#include <stdlib.h>

#define MaxWidth 20    //定义地图最大宽度

enum ElemType {
    blank,  //空白区域
    food,   //蛇的食物
    head,   //蛇的头部
    body,   //蛇的身体
    wall    //墙
};

//创建表示蛇各个结点的结构体
typedef struct SnakeNode {
    int x,y;
    struct SnakeNode *next;
    struct SnakeNode *prior;
}Node, *pNode;

void InitGame(void);
void PlayGame(void);

void InitMap(void);

void PaintMap(void);

#endif /* Snake_h */
