//
// Created by cheng on 2023/4/30.
//

#include <stdio.h>
#include <stdlib.h>

#define  ElemType int

typedef struct DNode{
    ElemType data;
    struct DNode *prior,*next;
}DNode,*DLinklist;

//头插创建链表
DLinklist listHeadInsert(DLinklist &L);

//按序号查找值
DNode * getElem(DLinklist L, int i);

//插入节点
bool listMidInsert(DLinklist &L, int i, ElemType e);

//删除节点
bool listMidDelete(DLinklist &L, int i, ElemType &e);

