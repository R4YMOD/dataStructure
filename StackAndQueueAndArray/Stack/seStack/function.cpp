//
// Created by cheng on 2023/5/1.
//

#include "stack.h"

//初始化栈
void initStack(SqStack &S){
    S.top = -1;
}

//判空
bool stackEmpty(SqStack S){
    if(S.top == -1) return true;
    return false;
}

//进栈
bool Push(SqStack &S, ElemType e){
    //栈满
    if(S.top == MaxSize - 1) {
        return false;
    }
    //栈非满
    S.top++;
    S.data[S.top] = e;
    return true;
}

//出栈
bool Pop(SqStack &S, ElemType &e){
    //栈空
    if(S.top == -1) return false;
    //栈非空
    e = S.data[S.top];
    S.top--;
    return true;
}

//栈顶
bool getTop(SqStack S, ElemType &e){
    if(S.top == -1) return false;
    e = S.data[S.top];
    return true;
}

//销毁
bool destroyStack(SqStack &S){
    S.top = -1;
}