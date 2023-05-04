//
// Created by cheng on 2023/5/1.
//

#include <stdlib.h>
#include <stdio.h>
#define ElemType char

typedef struct BiTNode{
    ElemType data;
    struct BiTNode *lChild ,*rChild;
}BiTNode,*BiTree;


//先序创建二叉树
BiTNode* createBiTree(BiTree &bt);
//访问结点数据
void visit(BiTNode bt);

//递归先序遍历
void PreOrder(BiTNode* bt);

//中序遍历
void PostOrder(BiTNode* bt);

/**
 * 二叉树的层次遍历
 * * 需要队列
 * */

typedef struct {
    BiTNode* data[20];
    int front;
    int rear;
}sqQueue;

//初始化数组队列
void initQueue(sqQueue& sq);

//入队
bool EnQueue(sqQueue &sq,BiTNode* e);

//出队
bool DeQueue(sqQueue &sq,BiTree &e);

//判空
bool isEmpty(sqQueue sq);
//层次遍历
void levelOrder(BiTNode* bt);

/** 二叉树遍历非递归
 * * 栈
 * ? 前序和后序遍历相似
 * ! 后序需要确定两个字节点都遍历完成
 **/

typedef struct LNode{
    BiTNode * data;
    struct LNode* next;
}LNode,*LiStack;

//初始化
void InitStack(LiStack& Ls);

//判断栈空
bool StackEmpty(LiStack &LS);

//进栈
bool Push(LiStack &LS,BiTree &e);

//出栈
bool Pop(LiStack &LS,BiTree &e);

//读栈顶
bool getTop(LiStack &LS,BiTree &e);

//先序遍历
void preOrder2(BiTree bt);

//非递归后序遍历
void postOrder2(BiTree);
