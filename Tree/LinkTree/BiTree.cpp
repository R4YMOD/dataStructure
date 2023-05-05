//
// Created by cheng on 2023/5/1.
//
#include "BiTree.h"

// ? 先序创建二叉树
BiTNode *createBiTree(BiTree &bt) {
    //接收结点数据
    char ch[2];
    scanf("%s", ch);
//    printf("输入节点:\n");

    if (ch[0] == '#') {
        bt = nullptr;
    } else {
        bt = (BiTNode *) malloc(sizeof(BiTNode));
        //创建树结点
//        printf("节点值为:%s\n",ch);
        bt->data = ch[0];
        bt->lChild = createBiTree(bt->lChild);
        bt->rChild = createBiTree(bt->rChild);
    }
    return bt;
}

//访问结点数据
void visit(BiTNode bt) {
    printf(" %c", bt.data);
}

//递归先序遍历
void PreOrder(BiTNode *bt) {
    if (bt != nullptr) {
        visit(*bt);
        PreOrder(bt->lChild);
        PreOrder(bt->rChild);
    }
}

//中序遍历
void PostOrder(BiTNode *bt) {
    if (bt != nullptr) {
        PostOrder(bt->lChild);
        visit(*bt);
        PostOrder(bt->rChild);
    }
}

/**
 * 二叉树的层次遍历
 * * 需要队列
 * */


//初始化数组队列
void initQueue(sqQueue &sq) {
    sq.front = 0;
    sq.rear = 0;
}

//入队
bool EnQueue(sqQueue &sq, BiTNode *e) {
    if ((sq.rear + 1) % 20 == sq.front) {
        return false;
    }
    sq.data[sq.rear] = e;
    sq.rear = (sq.rear + 1) % 20;
    return true;
}

//出队
bool DeQueue(sqQueue &sq, BiTree &e) {
    if (sq.rear == sq.front) {
        return false;
    }
    e = sq.data[sq.front];
    sq.front = (sq.front + 1) % 20;
    return true;
}

//判空
bool isEmpty(sqQueue sq) {
    if (sq.rear == sq.front) return true;
    return false;
}

//层次遍历
void levelOrder(BiTNode *bt) {
    sqQueue sq;
    BiTNode *pTNode = nullptr;
    if (bt == nullptr) {//树为空算法结束
        return;
    }
    initQueue(sq);
    EnQueue(sq, bt);
    while (!isEmpty(sq)) {//队列不为空
        DeQueue(sq, pTNode);
        printf(" %c", pTNode->data);
        if (pTNode->lChild != nullptr) {
            EnQueue(sq, bt->lChild);
        }
        if (pTNode->rChild != nullptr) {
            EnQueue(sq, bt->rChild);
        }
    }
}


/** 二叉树遍历非递归
 * * 栈
 * ? 前序和后序遍历相似
 * ! 后序需要确定两个字节点都遍历完成
 **/
//初始化
void InitStack(LiStack &Ls) {
    Ls = (LNode *) malloc(sizeof(LNode));
    Ls->next = nullptr;
}

//判断栈空
bool StackEmpty(LiStack &LS) {
    if (LS->next == nullptr) return true;
    return false;
}

//进栈
bool Push(LiStack &LS, BiTree &e) {
    LNode *temp = (LNode *) malloc(sizeof(LNode));
    temp->data = e;
    temp->next = LS->next;
    LS->next = temp;
    return true;
}

//出栈
bool Pop(LiStack &LS, BiTree &e) {
    if (LS->next == nullptr) {
        e = nullptr;
    }
    e = LS->next->data;
    LNode *p = LS->next;
    LS->next = LS->next->next;
    free(p);
    return true;
}

//读栈顶
bool getTop(LiStack &LS, BiTree &e) {
    if (LS->next == nullptr) {
        e = nullptr;
        return false;
    }
    e = LS->next->data;
    return true;
}

//先序遍历
void preOrder2(BiTree bt) {

    LiStack stack;
    BiTNode *p = bt;
    InitStack(stack);

    while (p != nullptr || !StackEmpty(stack)) {
        if (p != nullptr) {
            visit(*p);
            Push(stack, p);
            p = p->lChild;
        } else {
            Pop(stack, p);//while循环过滤掉了p为null的情况
            p = p->rChild;
        }
    }
}

//非递归后序遍历
/**
 * 1. 沿着根的左孩子以此入栈，直到左孩子为空
 * 2. 读栈顶
 *  1. 若右孩子不为空，且没有被访问过，跳转到右侧，左孩子依次入栈
 *  2. 否则，弹出元素
 *  * 难点：区分指针是从左子树还是右子树弹出
 * */
void postOrder2(BiTree bt) {
    LiStack stack;
    BiTNode *p = bt;
    BiTNode *aux = nullptr;//辅助指针
    InitStack(stack);
    while (p != nullptr || !StackEmpty(stack)) {
        if (p != nullptr) {
            Push(stack, p);
            p = p->lChild;
        } else {
            getTop(stack, p);
            //! 右子树存在且未被访问过
            if (p->rChild != nullptr && p->rChild != aux) {
                p = p->rChild;
            } else {
                Pop(stack, p);
                aux = p;
                printf(" %c", p->data);
                // ! 重置指针
                p = nullptr;
            }
        }
    }
}