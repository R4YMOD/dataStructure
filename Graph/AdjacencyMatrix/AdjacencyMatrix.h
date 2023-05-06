//
// Created by cheng on 2023/5/6.
//

#include <stdio.h>
#include <stdlib.h>

// 项目节点最大值
#define MaxVertexNum 4

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