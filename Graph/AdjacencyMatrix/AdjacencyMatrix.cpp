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
        printf("\n请输入第%d顶点元素:", i + 1);
        scanf("%s", topChar);
        graph.Vex[i] = topChar[0];
    }
    //连接
    printf("\n请输入边的数量:\n");
    int edgeNum;
    scanf_s("%d", &edgeNum);
    //对应两个节点及其位置G
    VertexType in, out;
    int inIndex, outIndex;
    for (int i = 0; i < edgeNum; ++i) {
        printf("请输入第%d条边(顶点-顶点)\n", i + 1);
        VertexType relateVertex[4];
        scanf("%s", relateVertex);
        in = relateVertex[0];
        out = relateVertex[2];
        inIndex = locateVertexVar(graph, in);
        outIndex = locateVertexVar(graph, out);
        graph.Edge[inIndex][outIndex] = 1;
        graph.Edge[outIndex][inIndex] = 1;
    }
}

//判断是否存在边
bool Adjacent(MGraph graph,VertexType x,VertexType y){
    int xIndex = locateVertexVar(graph,x);
    int yIndex = locateVertexVar(graph,y);
    if(graph.Edge[xIndex][yIndex] != 0 || graph.Edge[yIndex][xIndex] != 0){
        return true;
    }
    return false;
}

//返回第一个邻接点的顶点号
int firstNeighbor(MGraph graph,VertexType x){
    int xIndex = locateVertexVar(graph,x);
    for (int i = 0; i < graph.VertexNum; ++i) {
        if(graph.Edge[xIndex][i] != 0){
            return i;
        }
    }
    //没有找到
    return -1;

}

//返回下一个邻接的顶点号
int nextNeighbor(MGraph graph,VertexType x,VertexType y){
    int xIndex = locateVertexVar(graph,x);
    int yIndex = locateVertexVar(graph,y);
    for (int i = yIndex + 1; i < graph.VertexNum ; ++i) {
        if(graph.Edge[xIndex][i]){
            return i;
        }
    }
    //未找到
    return -1;
}
