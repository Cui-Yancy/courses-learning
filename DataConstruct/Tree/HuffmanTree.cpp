#include "HuffmanTree.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

//Ѱ�ҹ���������Ȩֵ��С�����������
static void Select(HuffmanTree HT, int end, int& m1, int& m2)
{
    //m1����С�ģ�m2�ǵڶ�С��
    m1 = 0;
    m2 = 0;
    for (int i = 1; i <= end; i++)
    {
        if (HT[i].parent == 0)
        {
            //Ѱ����������������Ϊ��СȨֵ��׼
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

//nΪҶ�ӽ�����������Ȩֵ�Ľ��
void HuffmanTreeCreate(HuffmanTree& HT, int n)
{
    if (n <= 1)
    {
        return;
    }

    //��ʼ�������������
    //n��Ҷ�ӽ������Ȩֵ
    //n-1��˫�׽������ֵ����ʼ��Ϊ0
    HT = new HuffmanTreeNode[2*n];
    for (int i = 1; i < 2*n; i++)
    {
        HT[i].parent = 0;
        HT[i].lchild = 0;
        HT[i].rchild = 0;
    }
    cout << "����������" << n << "�����Ȩ��ֵ" << endl;
    for (int i = 1; i <= n; i++)
    {
        cin >> HT[i].weight;
    }

    //������������
    //�ҵ����и������Ȩֵ��С���������
    //���������ϲ�Ϊ�µĸ����
    //�ظ�����������ֱ��ֻʣһ������㣬��һ��������
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

    //��ӡ��������
    for (int i = 1; i < 2 * n; i++)
    {
        cout << i << "\t" << HT[i].weight << "\t" << HT[i].parent << "\t" << HT[i].lchild << "\t" << HT[i].rchild << endl;
    }

#if 1
    //��ù���������
    //���Ӽ�Ϊ0���Һ��Ӽ�Ϊ1
    char** HC = new char* [n+1];    //ʹ�����е�1~n�������n��Ҷ�Ӷ�Ӧ
    char* code = new char[n];       //n��Ҷ�ӽ�㣬��Ҫ�ϲ�n-1�Σ������n-1������λ�������⻹��Ҫһ��������\0����������СΪn
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
