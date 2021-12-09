#include "DuLinkList.h"
#include <iostream>
using namespace std;

DuListNode* DuListLocate(DuLinkList L, int i)
{
    if (i < 1)
    {
        return NULL;
    }
    DuListNode* p = L->next;
    int j = 1;
    while (p && j != i)
    {
        p = p->next;
        j++;
    }
    return p;
}

//����Ԫ��ʱ����Ҫ�޸�4��ָ����
status DuListInsert(DuLinkList& L, int i, DuListElemType elem)
{
    DuListNode* p = DuListLocate(L, i);
    if (!p)
    {
        return ERROR;
    }
    DuListNode* s = new DuListNode;
    s->data = elem;
    s->next = p;
    s->prior = p->prior;
    p->prior->next = s;
    p->prior = s;
    return OK;
}

status DuListDelete(DuLinkList& L, int i, DuListElemType& elem)
{
    DuListNode* p = DuListLocate(L, i);
    if (!p)       //���ɾ����Ԫ��λ�ò�����
    {
        return ERROR;
    }
    p->prior->next = p->next;
    if (!p->next)                   //���ɾ���������һ����㣬ֻ��Ҫ��ǰ���ڵ��nextָ�����޸�Ϊ��
    {                               //������Ҫ����̽���priorͬʱ�޸�
        p->next->prior = p->prior;
    }
    elem = p->data;
    delete p;
    return OK;
}
