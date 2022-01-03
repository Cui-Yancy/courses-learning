#include "AMGraph.h"
#include <iostream>
using namespace std;
#include "LinkQueue.h"

static int LocateVertex(const AMGraph& G, AMVertexType v);

//按照顶点元素查找元素所在数组下标位置
//图中顶点元素不相同
static int LocateVertex(const AMGraph& G, AMVertexType v)
{
    for (int i = 0; i < G.VertexNum; i++)
    {
        if (G.Vertexs[i] == v)
        {
            return i;
        }
    }
    return -1;
}

//创建无向网
//无方向的边带权值的图
status CreateUDN(AMGraph& G)
{
    //1、输入顶点个数和边的个数
    //对顶点值进行初始化
    cout << "请输入无向网的顶点与边的个数：" << endl;
    cin >> G.VertexNum >> G.ArcNum;
    G.Visited = new int[G.VertexNum];
    cout << "请输入" << G.VertexNum << "个顶点的值" << endl;
    for (int i = 0; i < G.VertexNum; i++)
    {
        cin >> G.Vertexs[i];
        G.Visited[i] = 0;
    }

    //2、邻接矩阵初始化，网的初始化值为无穷大
    for (int i = 0; i < G.VertexNum; i++)
    {
        for (int j = 0; j < G.VertexNum; j++)
        {
            G.Arcs[i][j] = MaxInt;
        }
    }

    //3、创建邻接矩阵
    AMVertexType v1, v2;
    AMArcType w;
    int a, b;
    cout << "请输入各边信息，输入形式：A B 10，表示A和B元素之间有边，权值为10" << endl;
    for (int i = 0; i < G.ArcNum; i++)
    {
        cout << "第" << i + 1 << "个边信息：" << endl;
        cin >> v1 >> v2 >> w;
        a = LocateVertex(G, v1);
        b = LocateVertex(G, v2);
        G.Arcs[a][b] = w;
        G.Arcs[b][a] = w;
    }

    //以矩阵形式打印二维数组
    for (int i = 0; i < G.VertexNum; i++)
    {
        cout << "\t" << G.Vertexs[i];
    }
    cout << endl;
    for (int i = 0; i < G.VertexNum; i++)
    {
        cout << G.Vertexs[i];
        for (int j = 0; j < G.VertexNum; j++)
        {
            cout << "\t" << G.Arcs[i][j];
        }
        cout << endl;
    }
    return OK;
}

void ClearVisited(const AMGraph& G)
{
    for (int i = 0; i < G.VertexNum; i++)
    {
        G.Visited[i] = 0;
    }
}

void DFS(const AMGraph& G, int v)
{
    cout << G.Vertexs[v] << "\t";
    G.Visited[v] = 1;
    for (int i = 0; i < G.VertexNum; i++)
    {
        if (G.Arcs[v][i] != MaxInt && G.Visited[i] == 0)
        {
            DFS(G, i);
        }
    }
}

void BFS(const AMGraph& G, int v)
{
    LinkQueue Q;
    LinkQueueInit(Q);
    int VertexIndex;
    G.Visited[v] = 1;
    LinkQueueEnter(Q, v);
    while (!LinkQueueEmpty(Q))
    {
        LinkQueueExit(Q, VertexIndex);
        cout << G.Vertexs[VertexIndex] << "\t";
        for (int i = 0; i < G.VertexNum; i++)
        {
            if (G.Arcs[VertexIndex][i] != MaxInt && G.Visited[i] == 0)
            {
                LinkQueueEnter(Q, i);
                G.Visited[i] = 1;
            }
        }
    }
    LinkQueueDestroy(Q);
}
