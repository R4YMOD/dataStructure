//
// Created by cheng on 2023/5/6.
//

#include "AdjacencyMatrix.h"

//初始化
void initMGraph(MGraph &graph) {
    //初始化边表
    for (int i = 0; i < MaxVertexNum; ++i) {
        for (int j = 0; j < MaxVertexNum; ++j) {
            graph.Edge[i][j] = 0;
        }
    }
    //初始化当前顶点数
    graph.VertexNum = 0;
}


//查找元素在顶点表中的位置
int locateVertexVar(MGraph graph, VertexType e) {
    for (int i = 0; i < graph.VertexNum; ++i) {
        if (graph.Vex[i] == e) {
            return i;
        }
    }
    return -1;
}

//创建邻接矩阵
void createMGraph(MGraph &graph) {
    //接收节点个数
    int vertexNum;

    // 顶点值
    VertexType topChar[2];
    printf("请输入节点数(1~10):\n");
    scanf("%d", &vertexNum);
    graph.VertexNum = vertexNum;
    //顶点依次赋值
    for (int i = 0; i < vertexNum; i++) {
        printf("请输入第%d顶点元素:", i + 1);
        scanf("%s", topChar);
        graph.Vex[i] = topChar[0];
    }
    //连接
    printf("\n请输入边的数量:\n");
    int edgeNum;
    scanf_s("%d", &edgeNum);
    //对应两个节点及其位置
    VertexType in, out;
    int inIndex, outIndex;
    for (int i = 0; i < edgeNum; ++i) {
        printf("请输入第%d条边(顶点-顶点)\n", i + 1);
        VertexType relateVertex[4];
        scanf("%s", relateVertex);
        printf("%s", relateVertex);
        in = relateVertex[0];
        out = relateVertex[2];
        inIndex = locateVertexVar(graph, in);
        outIndex = locateVertexVar(graph, out);
        graph.Edge[inIndex][outIndex] = 1;
        graph.Edge[outIndex][inIndex] = 1;
    }

}