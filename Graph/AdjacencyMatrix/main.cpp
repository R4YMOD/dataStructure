//
// Created by cheng on 2023/5/6.
//
#include "AdjacencyMatrix.cpp"

int main() {
    system("chcp 65001");
    printf("Adjacency Matrix\n");
    MGraph mGraph;
    initMGraph(mGraph);
/**
*王道数据结构p203
*邻接矩阵
*         a b c d e
* a  0    0 1 0 1 0
* b  1    1 0 1 0 1
* c  2    0 1 0 1 1
* d  3    1 0 1 0 0
* e  4    0 1 1 0 0
* */
    createMGraph(mGraph);
    //返回第一个邻接
    VertexType x = 'a';
    printf("\n%c的第一个邻接点的索引为%d\n",x, firstNeighbor(mGraph,x));
    printf("\n%c的下一个邻接点的索引为%d\n",x, nextNeighbor(mGraph,x, 'b'));
    printf("hello");
}