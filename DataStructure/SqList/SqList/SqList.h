//
//  SqList.h
//  SqList
//
//  Created by Lyilan on 2021/4/28.
//

#ifndef SqList_h
#define SqList_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

// - - - - - 线性表的动态分配顺序存储结构 - - - - -
#define LIST_INIT_SIZE  10
#define LISTINCREMENT   10

typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
}SqList;

// - - - - - 线性表基本操作函数声明 - - - - -
Status InitList(SqList *L);
/*  操作结果：构造一个空的线性表L
 */

Status DestroyList(SqList *L);
/*  初始条件：线性表L已存在
 *  操作结果：销毁线性表L
 */

Status ClearList(SqList *L);
/*  初始条件：线性表L已存在
 *  操作结果：将L重制为空表
 */

Status ListEmpty(SqList L);
/*  初始条件：线性表L已存在
 *  操作结果：若L为空表，则返回TRUE,否则返回FALSE
 */

int ListLength(SqList L);
/*  初始条件：线性表L已存在
 *  操作结果：返回L中数据元素个数
 */

Status GetElem(SqList L, int i, ElemType *e);
/*  初始条件：线性表L已存在,1<=i<=ListLength(L)
 *  操作结果：用e返回L中第i个数据元素的值
 */

int LocateElem(SqList L, ElemType e, Status(*compare)(ElemType, ElemType));
/*  初始条件：线性表L已存在,compare()是数据元素判定函数
 *  操作结果：返回L中第1个与e满足关系compare()的数据元素的位序。
 *          若这样的数据元素不存在，则返回值为0
 */

Status PriorElem(SqList L, ElemType cur_e, ElemType *pre_e);
/*  初始条件：线性表L已存在
 *  操作结果：若cur_e是L的数据元素，且不是第一个，则用pre_e返回它的前驱
 *          否则操作失败，pre_e无定义
 */

Status NextElem(SqList L, ElemType cur_e, ElemType *next_e);
/*  初始条件：线性表L已存在
 *  操作结果：若cur_e是L的数据元素，且不是最后一个，则用next_e返回它的后继
 *          否则操作失败，next_e无定义
 */

Status ListInsert(SqList *L, int i, ElemType e);
/*  初始条件：线性表L已存在，1<=i<=ListLength(L)+1
 *  操作结果：在L中第i个位置之前插入新的数据元素e,L的长度加1
 */

Status ListDelete(SqList *L, int i, ElemType *e);
/*  初始条件：线性表L已存在且非空，1<=i<=ListLeng(L)+1
 *  操作结果：删除L中的第i个数据元素，并用e返回其值，L的长度减1
 */

Status ListTraverse(SqList L, Status(*visit)(ElemType));
/*  初始条件：线性表已存在
 *  操作结果：依次对L的每个数据元素调用visit()。一旦visit()失败，则操作失败
 */

// - - - - - 内部函数声明 - - - - -
Status IsEqual(ElemType e1, ElemType e2);
/*  操作结果：若e1和e2相等，返回TRUE，否则返回FALSE
 */
Status PrintElem(ElemType e);
/*  操作结果：打印元素e
 */

#endif /* SqList_h */
