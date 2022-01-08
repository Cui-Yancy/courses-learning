#include "SeqSearch.h"
#include <iostream>
using namespace std;

int SeqSearch(SeqSearchTable T, SeqKeyType key)
{
    //第一种查找方法，每次循环需要判断两次，i>0  key[i]==key
    //int i = 0;
    //for (i = T.Length; i > 0; i--)
    //{
    //    if (T.Key[i] == key)
    //    {
    //        return i;
    //    }
    //}
    //return i;

    //第二种查找算法
    //设置一个哨兵，将0号位置设置为查找值
    //一定会找到这个值，如果位置为0表示没找到，其他则找到了
    //每次只需要判断一次，不需要判断i>0，可以将时间缩短一半
    int i = 0;
    T.Key[0] = key;
    for (i = T.Length; T.Key[i] != key; i--);
    return i;
}

//二分查找法，适用于递增序列
int BinSearch(SeqSearchTable T, SeqKeyType key)
{
    int low = 1;
    int high = T.Length;
    while (high >= low)
    {
        int mid = (high + low) / 2;
        if (T.Key[mid] == key)
        {
            return mid;
        }
        else if (key > T.Key[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return 0;
}

