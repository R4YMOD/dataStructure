//
// Created by cheng on 2023/4/16.
//

#include <stdio.h>
#include <stdlib.h>

#define  ElemType int
/*
 * 单链表节点
 * */
typedef struct LNode {
    ElemType data;
    struct LNode *next;
} LNode, *LinkList;

//头插创建链表
LinkList listHeadInsert(LinkList &L);

//尾插创建链表
LinkList listTailInsert(LinkList &L);

//按序号查找值
LNode *getElem(LinkList L, int i);

//按值查找表节点
LNode *locateElem(LinkList L, ElemType e);

//插入节点
bool listMidInsert(LinkList &L, int i, ElemType e);

//删除节点
bool listMidDelete(LinkList &L, int i, ElemType &e);

//求表长
int length(LinkList L);