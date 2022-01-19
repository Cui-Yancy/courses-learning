#include "SelectSort.h"
#include "InsertSort.h"
#include <iostream>
using namespace std;

//简单选择排序
status SelectSort(SortSeqList& L)
{
    for (int i = 1; i <= L.Length - 1; i++)     //一共需要n-1趟
    {
        int min = i;
        for (int j = i+1; j <= L.Length; j++)   //每一趟从下一个元素开始找最小值
        {
            if (L.Arry[j].key < L.Arry[min].key)//记录最小值位置
            {
                min = j;
            }
        }
        if (min != i)   //交换最小值的位置
        {
            SortElem temp = L.Arry[min];
            L.Arry[min] = L.Arry[i];
            L.Arry[i] = temp;
        }
    }
    return OK;
}

void SelectSortDemo()
{
    SortSeqList L;
    SortSeqListInit(L);
    showSortSeqList(L);
    SelectSort(L);
    showSortSeqList(L);
}