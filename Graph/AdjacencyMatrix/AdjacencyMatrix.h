//
// Created by cheng on 2023/5/6.
//

#include <stdio.h>
#include <stdlib.h>

// 项目节点最大值
#define MaxVertexNum 5

//定点数据类型
typedef char VertexType;
//边权值
typedef int EdgeType;// 999代表无穷大

typedef struct {
    //当前顶点数
    int VertexNum;
    //顶点表
    VertexType Vex[MaxVertexNum];
    //边表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];
}MGraph;

//初始化
void initMGraph(MGraph &graph);

//查找元素在顶点表中的位置
int locateVertexVar(MGraph graph,VertexType e);

//创建邻接矩阵
void createMGraph(MGraph &graph);

//判断是否存在边
bool Adjacent(MGraph graph,VertexType x,VertexType y);

//返回第一个邻接点的顶点号
int firstNeighbor(MGraph graph,VertexType x);

//返回下一个邻接的顶点号
int nextNeighbor(MGraph graph,VertexType x,VertexType y);

/**
 * 访问数组
 * */
bool visited[MaxVertexNum];
//广度优先搜索
void BFSTraverse(MGraph graph);
void BFS(MGraph graph,int v);
//深度优先搜素
void DFSTraverse(MGraph graph);
void DFS(MGraph graph,int v);