//
// Created by cheng on 2023/5/1.
//

#include <stdio.h>
#include <stdlib.h>

#define MaxSize 20
#define ElemType int
typedef struct {
    ElemType data[MaxSize];
    int top;
} SqStack;

//初始化栈
void initStack(SqStack &S);

//判空
bool stackEmpty(SqStack S);

//进栈
bool Push(SqStack &S, ElemType e);

//出栈
bool Pop(SqStack &S, ElemType &e);

//栈顶
bool getTop(SqStack S, ElemType &e);

//销毁
bool destroyStack(SqStack &S);