//
// Created by cheng on 2023/5/1.
//

#include <stdlib.h>
#include <stdio.h>

#define ElemType int

typedef struct LinkNode{
    ElemType data;
    struct LinkNode *next;
}*LiStack,LinkNode ;

/**
 * 带头节点
 * 头指针指向的为栈顶
 * */

//初始化
void InitStack(LiStack& Ls){
    Ls->next = nullptr;
}

//判断栈空
bool StackEmpty(LiStack &LS);

//进栈
bool Push(LiStack &LS,ElemType e);

//出栈
bool Pop(LiStack &LS,ElemType &e);

//读栈顶
bool getTop(LiStack &LS,ElemType &e);

//销毁栈
bool DestroyStack(LiStack &LS);