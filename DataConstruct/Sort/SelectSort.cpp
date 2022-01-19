#include "SelectSort.h"
#include "InsertSort.h"
#include <iostream>
using namespace std;

//��ѡ������
status SelectSort(SortSeqList& L)
{
    for (int i = 1; i <= L.Length - 1; i++)     //һ����Ҫn-1��
    {
        int min = i;
        for (int j = i+1; j <= L.Length; j++)   //ÿһ�˴���һ��Ԫ�ؿ�ʼ����Сֵ
        {
            if (L.Arry[j].key < L.Arry[min].key)//��¼��Сֵλ��
            {
                min = j;
            }
        }
        if (min != i)   //������Сֵ��λ��
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