//
// Created by cheng on 2023/5/1.
//

#include "seQueue.h"

//初始化
void initQueue(SqQueue &Q){
    Q.front = 0;
    Q.rear = 0;
}

//判空
bool isEmpty(SqQueue Q){
    if(Q.rear == Q.front) return true;
    return false;
}

//入队
bool EnQueue(SqQueue &Q,ElemType e){
    //队列满
    if((Q.rear+1)%MaxSize == Q.front) return false;
    //队列空
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear+1)%MaxSize;
    return true;
}
//出队
bool DeQueue(SqQueue &Q,ElemType &e){
    //队列空
    if(Q.rear == Q.front) return false;
    //队非空
    e = Q.data[Q.front];
    Q.front = (Q.front +1)%MaxSize;
    return true;
}
