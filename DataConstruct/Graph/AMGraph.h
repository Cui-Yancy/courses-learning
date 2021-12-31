#pragma once
#include "define.h"

#define MaxInt          32767
#define MaxVertexNum    100

typedef char AMVertexType;
typedef int AMArcType;

typedef struct
{
    AMVertexType Vertexs[MaxVertexNum];         //顶点元素数组
    AMArcType Arcs[MaxVertexNum][MaxVertexNum]; //边或弧形成的邻接矩阵
    int VertexNum;  //图中的顶点个数
    int ArcNum;     //图中的边或弧的个数
}AMGraph;

status CreateUDN(AMGraph& G);
