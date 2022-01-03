#include "ALGraph.h"
#include <iostream>
using namespace std;
#include "LinkQueue.h"
#include <queue>

static int LocateVertex(const ALGraph& G, ALVertexType v)
{
    for (int i = 0; i < G.VertexNum; i++)
    {
        if (G.Vertexs[i].data == v)
        {
            return i;
        }
    }
    return -1;
}

//使用邻接表创建无向网
status CreateUDN(ALGraph& G)
{
    //1、初始化顶点表，输入顶点值，将指针域置为空
    cout << "请依次输入无向网的顶点和边的个数：" << endl;
    cin >> G.VertexNum >> G.ArcNum;
    G.Visited = new int[G.VertexNum];
    cout << "请输入" << G.VertexNum << "个顶点的数值：" << endl;
    for (int i = 0; i < G.VertexNum; i++)
    {
        cin >> G.Vertexs[i].data;
        G.Vertexs[i].firstArc = NULL;
        G.Visited[i] = 0;
    }

    //2、输入边的信息，初始化边链表
    cout << "请输入无向网" << G.ArcNum << "个边的信息，例如，a b 10" << endl;
    ALVertexType v1, v2;
    InfoType w;
    int i, j;
    for (int k = 0; k < G.ArcNum; k++)
    {
        cout << "第" << k + 1 << "条边：" << endl;
        cin >> v1 >> v2 >> w;
        i = LocateVertex(G, v1);
        j = LocateVertex(G, v2);

        ArcNode* p1 = new ArcNode;
        p1->info = w;
        p1->VertexIndex = j;
        p1->nextArc = G.Vertexs[i].firstArc;
        G.Vertexs[i].firstArc = p1;

        ArcNode* p2 = new ArcNode;
        p2->info = w;
        p2->VertexIndex = i;
        p2->nextArc = G.Vertexs[j].firstArc;
        G.Vertexs[j].firstArc = p2;
    }

    //打印邻接表
    for (int k = 0; k < G.VertexNum; k++)
    {
        cout << G.Vertexs[k].data;
        ArcNode* p = G.Vertexs[k].firstArc;
        while (p)
        {
            cout << "\t" << G.Vertexs[p->VertexIndex].data << "," << p->info;
            p = p->nextArc;
        }
        cout << endl;
    }
    return OK;
}

void ClearVisited(const ALGraph& G)
{
    for (int i = 0; i < G.VertexNum; i++)
    {
        G.Visited[i] = 0;
    }
}

void DFS(const ALGraph& G, int v)
{
    cout << G.Vertexs[v].data << "\t";
    G.Visited[v] = 1;
    ArcNode* p = G.Vertexs[v].firstArc;
    while (p)
    {
        if (G.Visited[p->VertexIndex] == 0)
        {
            DFS(G, p->VertexIndex);
        }
        p = p->nextArc;
    }
}

void BFS(const ALGraph& G, int v)
{
    LinkQueue Q;
    LinkQueueInit(Q);
    ArcNode* p;
    int VertexIndex;
    G.Visited[v] = 1;
    LinkQueueEnter(Q, v);
    while (!LinkQueueEmpty(Q))
    {
        LinkQueueExit(Q, VertexIndex);
        cout << G.Vertexs[VertexIndex].data << "\t";
        p = G.Vertexs[VertexIndex].firstArc;
        while (p)
        {
            if (G.Visited[p->VertexIndex] == 0)
            {
                LinkQueueEnter(Q, p->VertexIndex);
                G.Visited[p->VertexIndex] = 1;
            }
            p = p->nextArc;
        }
    }
    LinkQueueDestroy(Q);
}
