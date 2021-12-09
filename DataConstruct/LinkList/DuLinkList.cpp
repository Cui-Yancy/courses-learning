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

//插入元素时，需要修改4个指针域
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
    if (!p)       //如果删除的元素位置不存在
    {
        return ERROR;
    }
    p->prior->next = p->next;
    if (!p->next)                   //如果删除的是最后一个结点，只需要将前趋节点的next指针域修改为空
    {                               //否则还需要将后继结点的prior同时修改
        p->next->prior = p->prior;
    }
    elem = p->data;
    delete p;
    return OK;
}
