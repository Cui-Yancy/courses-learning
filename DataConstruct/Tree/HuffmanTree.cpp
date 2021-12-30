#include "HuffmanTree.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

//寻找哈夫曼树中权值最小的两个根结点
static void Select(HuffmanTree HT, int end, int& m1, int& m2)
{
    //m1是最小的，m2是第二小的
    m1 = 0;
    m2 = 0;
    for (int i = 1; i <= end; i++)
    {
        if (HT[i].parent == 0)
        {
            //寻找最初两个根结点作为最小权值基准
            //m1<=m2
            if (!m1)
            {
                m1 = i;
                continue;
            }
            if (!m2)
            {
                m2 = i;
                if (HT[m1].weight > HT[m2].weight)
                {
                    int t = m1;
                    m1 = m2;
                    m2 = t;
                }
                continue;
            }
            if (HT[i].weight<HT[m2].weight)
            {
                m2 = i;
            }
            if (HT[m1].weight > HT[m2].weight)
            {
                int t = m1;
                m1 = m2;
                m2 = t;
            }
        }
    }

}

//n为叶子结点个数，即带权值的结点
void HuffmanTreeCreate(HuffmanTree& HT, int n)
{
    if (n <= 1)
    {
        return;
    }

    //初始化哈夫曼树结点
    //n个叶子结点输入权值
    //n-1个双亲结点所有值都初始化为0
    HT = new HuffmanTreeNode[2*n];
    for (int i = 1; i < 2*n; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    cout << "请依次输入" << n << "个结点权重值" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }

    //构建哈夫曼树
    //找到所有根结点中权值最小的两个结点
    //将这两个合并为新的根结点
    //重复上述操作，直到只剩一个根结点，即一个二叉树
    int m1, m2;
    for (int i = n + 1; i < 2*n; i++)
    {
        Select(HT, i - 1, m1, m2);
        HT[i].lchild = m1;
        HT[i].rchild = m2;
        HT[i].weight = HT[m1].weight + HT[m2].weight;
        HT[m1].parent = i;
        HT[m2].parent = i;
    }

    //打印哈夫曼树
    for (int i = 1; i < 2 * n; i++)
    {
        cout << i << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
    }

#if 1
    //获得哈夫曼编码
    //左孩子记为0，右孩子记为1
    char** HC = new char* [n+1];    //使用其中的1~n项，用于与n个叶子对应
    char* code = new char[n];       //n个叶子结点，需要合并n-1次，最多有n-1个编码位数，此外还需要一个结束符\0，因此数组大小为n
    code[n - 1] = '\0';
    for (int i = 1; i <= n; i++)
    {
        int NodePos = i;
        int ChPos = n - 2;
        while (HT[NodePos].parent != 0)
        {
            if (HT[HT[NodePos].parent].lchild == NodePos)
            {
                code[ChPos] = '0';
            }
            else
            {
                code[ChPos] = '1';
            }
            NodePos = HT[NodePos].parent;
            ChPos--;
        }
        HC[i] = new char[n - ChPos - 1];
        memcpy(HC[i], &code[ChPos + 1], n - ChPos - 1);
    }

    float sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cout << i << "\t" << HC[i] << "\t" << strlen(HC[i]) << endl;
        sum += HT[i].weight * strlen(HC[i]);
    }
    cout << sum << endl;
    delete [] code;
#endif
}
