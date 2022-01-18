#include "SwapSort.h"
#include "InsertSort.h"
#include <iostream>
using namespace std;

status BubbleSort(SortSeqList& L)
{
    for (int i = 0; i < L.Length - 1; i++)
    {
        bool NoExchange = true;
        for (int j = 1; j <= L.Length - i - 1; j++)
        {
            if (L.Arry[j].key > L.Arry[j + 1].key)
            {
                NoExchange = false;
                L.Arry[0] = L.Arry[j];
                L.Arry[j] = L.Arry[j + 1];
                L.Arry[j + 1] = L.Arry[0];
            }
        }
        if (NoExchange)
        {
            break;
        }
    }
    return OK;
}

//快速排序，先找一个中心点，将其分成两部分
status QuickSort(SortSeqList& L, int low, int high)
{
    if (low >= high)
    {
        return OK;
    }
    int start = low;
    int end = high;
    int mid = 1;
    L.Arry[0] = L.Arry[low];        //默认将排序序列的第一个元素作为中心点
    bool left = 1;                  //用于标记空缺位置在左侧还是右侧
    while (low < high)
    {
        if (left)                   //空缺在左侧，就在右侧寻找小于中心点的元素进行交换
        {
            if (L.Arry[high].key < L.Arry[0].key)
            {
                L.Arry[low] = L.Arry[high];
                left = 0;
            }
            else
            {
                high--;
            }
        }
        else                        //空缺在右侧，就在左侧寻找大于中心点的元素进行交换
        {
            if (L.Arry[low].key >= L.Arry[0].key)
            {
                L.Arry[high] = L.Arry[low];
                left = 1;
            }
            else
            {
                low++;
            }
        }
    }
    mid = high;
    L.Arry[mid] = L.Arry[0];

    QuickSort(L, start, mid - 1);    //对两个子序列进行排序
    QuickSort(L, mid + 1, end);
    return OK;
}

void SwapSortDemo()
{
    SortSeqList L;
    SortSeqListInit(L);
    cout << "原始数据：" << endl;
    showSortSeqList(L);

    BubbleSort(L);
    cout << "冒泡排序结果：" << endl;
    showSortSeqList(L);
    cout << endl;

    SortSeqListInit(L);
    cout << "原始数据：" << endl;
    showSortSeqList(L);

    QuickSort(L, 1, L.Length);
    cout << "快速排序结果：" << endl;
    showSortSeqList(L);
}
