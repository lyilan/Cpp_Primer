//
//  Triplet.h
//  Triplet
//
//  Created by Lyilan on 2021/4/24.
//

#ifndef Triplet_h
#define Triplet_h

#include <stdio.h>
#include <stdlib.h>
#include "Status.h"

// - - - - - 三元组结构定义 - - - - -
typedef int ElemType;

typedef struct Triplet
{
    ElemType e1;
    ElemType e2;
    ElemType e3;
}Tri, *pTri;

// - - - - - 基本操作的声明 - - - - -
Status InitTriplet(pTri *T, ElemType v1, ElemType v2, ElemType v3);
/*  操作结果：构造了三元组T，元素e1，e2和e3分别被赋以参数v1，v2和v3的值
 */
 
Status DestroyTriplet(pTri *T);
/*  操作结果：三元组T被销毁
 */

Status Get(Tri T, int i, ElemType *e);
/*  初始条件：三元组T已存在，1<=i<=3
 *  操作结果：用e返回T的第i元的值
 */

Status Put(pTri T, int i, ElemType e);
/*  初始条件：三元组T已存在
 *  操作结果：改变T的第i元的值为e
 */

Status IsAscending(Tri T);
/*  初始条件：三元组T已存在
 *  操作条件：如果T的三个元素按升序排列，则返回1，否则返回0
 */

Status IsDescending(Tri T);
/*  初始条件：三元组T已存在
 *  操作条件：如果T的三个元素按降序排列，则返回1，否则返回0
 */

Status Max(Tri T, ElemType *e);
/*  初始条件：三元组T已存在
 *  操作结果：用e返回T的3个元素中的最大值
 */

Status Min(Tri T, ElemType *e);
/*  操作条件：三元组T已存在
 *  操作结果：用e返回T的3个元素中的最小值
 */

#endif /* Triplet_h */
