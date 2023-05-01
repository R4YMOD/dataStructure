//
// Created by cheng on 2023/5/1.
//

#include <stdio.h>
#include <stdlib.h>
#define ElemType int

//队列节点
typedef struct LinkNode{
    ElemType data;
    struct LinkNode * next;
}LinkNode;

//队列头结点

typedef struct{
    LinkNode *front,*rear;
}LinkQueue;

//初始化
void initQueue(LinkQueue &L);

//判空
bool isEmpty(LinkQueue L);

//入队
void enQueue(LinkQueue &L,ElemType e);

//出队
bool deQueue(LinkQueue &L,ElemType &e);