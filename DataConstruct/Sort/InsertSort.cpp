#include "InsertSort.h"
#include <iostream>
using namespace std;
#include <stdlib.h>
#include <ctime>

//��ʾ����˳���
static void showList(const SortSeqList& L)
{
    for (int i = 0; i < L.Length; i++)
    {
        cout << L.Arry[i].key;
        if (i != L.Length - 1)
        {
            cout << " ";
        }
    }
    cout << endl;
}

//����˳����ʼ��
status SortSeqListInit(SortSeqList& L)
{
    srand((unsigned int)time(NULL));
    int n = 0;
    cout << "����������������" << endl;
    cin >> n;
    L.Arry = new SortElem[SORTMAXSIZE];
    for (int i = 0; i < n; i++)
    {
        L.Arry[i].key = rand() % 101;
    }
    L.Length = n;
    return OK;
}

//˳���������
//������ץ�ƣ�ÿһ�ν��µ�Ԫ�ز�����������
status SeqInsertSort(SortSeqList& L)
{
    for (int i = 1; i < L.Length; i++)
    {
        SortKeyType x = L.Arry[i].key;
        int j;
        for (j = i - 1; j >= 0 && L.Arry[j].key > x; j--)
        {
            L.Arry[j + 1] = L.Arry[j];
        }
        L.Arry[j + 1].key = x;
    }
    return OK;
}

//����˳���չʾdemo
void SortSeqListDemo()
{
    SortSeqList L;
    SortSeqListInit(L);
    showList(L);
    SeqInsertSort(L);
    showList(L);
}
