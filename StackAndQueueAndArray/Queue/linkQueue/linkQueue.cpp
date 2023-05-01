//
// Created by cheng on 2023/5/1.
//
#include "linkQueue.h"


//初始化
void initQueue(LinkQueue &L){
//建立头结点
L.front = (LinkNode *) malloc(sizeof(LinkNode));
L.rear = L.front;

//头结点下一节点为空
L.front->next = nullptr;

}

//判空
bool isEmpty(LinkQueue L){
    if(L.front == L.rear) return true;
    return false;
}

//入队
void enQueue(LinkQueue &L,ElemType e){
    LinkNode *p = (LinkNode*) malloc(sizeof (LinkNode));
    p->data = e;
    p->next = nullptr;
    L.rear->next = p;
    L.rear = p;
}

//出队
bool deQueue(LinkQueue &L,ElemType &e){
    if(L.rear == L.front) return false;
    LinkNode *p = L.front->next;
    e = p->data;
    L.front->next = p->next;
    free(p);
    return true;
}