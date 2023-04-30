//
// Created by cheng on 2023/4/16.
//
#include "linkList.h"

//头插创建链表
LinkList listHeadInsert(LinkList &L) {
    //创建头指针
    L = (LinkList) malloc(sizeof(LNode));
    //初始化空表
    L->next = nullptr;
    //插入元素
    ElemType x;
    LNode *s;
    scanf("%d", &x);
    while (x != 9999) {
        s = (LNode *) malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;
        scanf("%d", &x);
    }
    return L;
}

//尾插创建链表
LinkList listTailInsert(LinkList &L) {
    /*创建头节点*/
    L = (LinkList) malloc(sizeof(LNode));
    L->next = nullptr;
    /*插入节点*/
    //尾节点
    LNode *r = L;
    //插入
    ElemType x;
    LNode *s;
    scanf("%d",&x);
    while (x != 9999){
        s = (LNode*) malloc(sizeof (LNode));
        s->data = x;
        r->next = s;
        r = s;
    }
    r->next = nullptr;
    return L;
}

//按序号查找值
LNode *getElem(LinkList L, int i){
    int j = 1;
    LNode *p = L->next;
    //查找第一个元素
    if(i == 1){
        return p;
    }
    //不是第一个元素
    while (p != nullptr && j<i){//j == i 返回
        p = p->next;
        j++;
    }
    return p;
}

//按值查找表节点
LNode *locateElem(LinkList L, ElemType e){
    //表为空
    if(L->next == nullptr)return nullptr;
    //查找
    LNode * p = L->next;
    while (p != nullptr && p->data != e){
        p = p->next;
    }
    return p;
}

//插入节点
bool listMidInsert(LinkList &L, int i, ElemType e){
    //找到i-1尾的指针
    LNode *pro = getElem(L, i - 1);
    if(pro == nullptr) return false;
    LNode *p = (LNode *) malloc(sizeof (LNode));
    p->data =  e;
    p->next = pro->next;
    pro->next = p;
    return true;
}

//删除节点
bool listMidDelete(LinkList &L, int i, ElemType &e){
    LNode *pre = getElem(L,i-1);
    if(pre == nullptr) return false;
    LNode * litter = pre->next;
    pre->next = litter->next;
    free(litter);
    return true;
}

//求表长
int length(LinkList L){
    LNode *p = L->next;
    int length;
    length = 0;
    while (p != nullptr){
        length++;
        p = p->next;
    }
    return length;
}