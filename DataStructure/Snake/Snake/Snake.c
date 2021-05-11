//
//  Snake.c
//  Snake
//
//  Created by Lyilan on 2021/4/24.
//

#include "Snake.h"

enum ElemType SnakeMap[MaxWidth][MaxWidth];


void InitGame(void)
{
    printf("欢迎来到贪吃蛇!\n");
    InitMap();
    PaintMap();
}


void InitMap(void)
{
    for(int i = 0; i < MaxWidth; i++)
    {
        for(int j = 0; j < MaxWidth; j++)
        {
            if(i == 0 || j == 0 || i == MaxWidth - 1 || j == MaxWidth - 1)
                SnakeMap[i][j] = wall;
            else
                SnakeMap[i][j] = blank;
        }
    }
    SnakeMap[1][1]=body;
    SnakeMap[1][2]=body;
    SnakeMap[1][3]=head;
    return;
}

void PaintMap(void)
{
    system("clear");
    for(int i = 0; i < MaxWidth; i++)
    {
        for(int j = 0; j < MaxWidth; j++)
        {
            switch(SnakeMap[i][j])
            {
                case blank:
                    printf("  ");
                    break;
                case food:
                    printf("🍞");
                    break;
                case head:
                    printf("🐸");
                    break;
                case body:
                    printf("🐍");
                    break;
                case wall:
                    printf("🧱");
                    break;
            }
        }
        printf("\n");
    }
    return;
}
