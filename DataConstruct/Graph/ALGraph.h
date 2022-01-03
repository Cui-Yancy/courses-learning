#pragma once

#include "define.h"

#define ALMaxVertexNum  100         //最大顶点个数

typedef char ALVertexType;           //邻接表顶点类型
typedef int InfoType;               //边或弧的信息类型

//边或弧结点定义
typedef struct ArcNode
{
    int VertexIndex;                //边或弧指向的顶点所在顶点数组下标
    struct ArcNode* nextArc;        //指向下一个边或弧结点
    InfoType info;                  //边或弧所包含的信息，例如权值
}ArcNode;

//表头顶点数组元素定义
typedef struct
{
    ALVertexType data;              //顶点元素值
    ArcNode* firstArc;              //指向第一个边或弧结点
}VertexNode;

typedef struct
{
    VertexNode Vertexs[ALMaxVertexNum];
    int VertexNum;
    int ArcNum;
    int* Visited;
}ALGraph;

status CreateUDN(ALGraph& G);
void ClearVisited(const ALGraph& G);
void DFS(const ALGraph& G, int v);
void BFS(const ALGraph& G, int v);
