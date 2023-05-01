//
// Created by cheng on 2023/5/1.
//

#include <stdio.h>
#include <stdlib.h>

/**
 * 循环队列
 * 少使用一个元素作为标志位
 * */
#define ElemType int
#define MaxSize 10
typedef struct {
    ElemType data[MaxSize];
    int front;
    int rear;
}SqQueue;

//初始化
void initQueue(SqQueue &Q);

//判空
bool isEmpty(SqQueue Q);

//入队
bool EnQueue(SqQueue &Q,ElemType e);

//出队
bool DeQueue(SqQueue &Q,ElemType &e);
