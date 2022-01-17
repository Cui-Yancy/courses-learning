﻿#include "InsertSort.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>

//显示排序顺序表
static void showList(const SortSeqList& L)
{
    for (int i = 1; i <= L.Length; i++)
    {
        cout << L.Arry[i].key;
        if (i != L.Length)
        {
            cout << " ";
        }
    }
    cout << endl;
}

//排序顺序表初始化
status SortSeqListInit(SortSeqList& L)
{
    srand((unsigned int)time(NULL));
    int n = 0;
    cout << "请输入随机排序表长度" << endl;
    cin >> n;
    L.Arry = new SortElem[SORTMAXSIZE + 1];
    for (int i = 1; i <= n; i++)
    {
        L.Arry[i].key = rand() % 101;
    }
    L.Length = n;
    return OK;
}

//顺序插入排序
//类似于抓牌，每一次将新的元素插入有序序列
status SeqInsertSort(SortSeqList& L)
{
    for (int i = 2; i <= L.Length; i++)
    {
        L.Arry[0] = L.Arry[i];
        int j;
        for (j = i - 1; L.Arry[j].key > L.Arry[0].key; j--)
        {
            L.Arry[j + 1] = L.Arry[j];
        }
        L.Arry[j + 1] = L.Arry[0];
    }
    return OK;
}

//排序顺序表展示demo
void SortSeqListDemo()
{
    SortSeqList L;
    SortSeqListInit(L);
    showList(L);
    SeqInsertSort(L);
    showList(L);
}
