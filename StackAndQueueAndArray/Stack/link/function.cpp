//
// Created by cheng on 2023/5/1.
//
#include "linkStack.h"

//判断栈空
bool StackEmpty(LiStack &LS){
    if(LS->next == nullptr) return true;
    return true;
}

//进栈
bool Push(LiStack &LS,ElemType e){
    LinkNode *p = (LinkNode*) malloc(sizeof (LinkNode));
    p->data = e;
    p->next = LS->next;
    LS->next = p;
    return true;
}

//出栈
bool Pop(LiStack &LS,ElemType &e){
    if(LS->next == nullptr) return false;
    LinkNode *p = LS->next;
    e = p->data;
    LS->next = p->next;
    free(p);
    return true;
}

//读栈顶
bool getTop(LiStack &LS,ElemType &e){
    if(LS->next == nullptr) return false;
    e = LS->next->data;
    return true;
}

//销毁栈
bool DestroyStack(LiStack &LS){
    LinkNode *p = nullptr;
    while (LS->next != nullptr){
        p = LS->next;
        LS->next = p->next;
        free(p);
    }
    return true;
}