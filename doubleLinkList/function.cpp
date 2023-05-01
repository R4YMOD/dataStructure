//
// Created by cheng on 2023/4/30.
//
#include "doubleLinkList.h"

//头插创建链表
DLinklist listHeadInsert(DLinklist &L){
    //创建表头
    L = (DLinklist) malloc(sizeof (DNode));
    L->next = nullptr;
    L->prior = nullptr;

    //插入
    DNode *p ;
    ElemType x;
    scanf("%d",&x);
    while (x != 9999){
        p = (DNode *)malloc(sizeof (DNode));
        p->next = L->next;
        if(L->next != nullptr){
            L->next->prior =p;
        }
        p->prior = L;
        L->next = p;

        scanf("%d",&x);
    }
    return L;
}

//按序号查找值
DNode * getElem(DLinklist L, int i){
    //错误信息
    if(i < 1 && L->next == nullptr){
        return nullptr;
    }
    //查找
    int index = 1;
    DNode *p = L->next;
    while (p != nullptr && index < i){
        p = p->next;
        i++;
    }
    return p;
}

//插入节点
bool listMidInsert(DLinklist &L, int i, ElemType e){
    DNode *pNode = getElem(L, i - 1);
    if(pNode == nullptr) return false;
    //插入
    DNode *qNode = (DNode*) malloc(sizeof (DNode));
    qNode->data = e;
    qNode->next = pNode->next;
    if(pNode->next != nullptr){
        pNode->next->prior = qNode;
    }
    pNode->next =qNode;
    qNode->prior = pNode;;
    return true;
}

//删除节点
bool listMidDelete(DLinklist &L, int i, ElemType &e){
    //找到第 i-1 个节点
    DNode *p = getElem(L,i-1);
    if(p == nullptr || p->next == nullptr){//没有第i-1个节点和没有第i个节点
        return false;
    }
    DNode *q = p->next;
    p->next = q->next;
    q->next->prior = p;
    e = q->data;
    free(q);
    return true;
}