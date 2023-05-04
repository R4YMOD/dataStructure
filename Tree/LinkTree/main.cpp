//
// Created by cheng on 2023/5/1.
//
#include "BiTree.cpp"

int main() {
    //解决控制台乱码
    system("chcp 65001");
    BiTNode *bt;

    //创建树
    createBiTree(bt);
    printf("先序遍历\n");
    PreOrder(bt);
    printf("\n层次遍历\n");
    levelOrder(bt);
    printf("\n先序遍历\n");
    preOrder2(bt);
} 