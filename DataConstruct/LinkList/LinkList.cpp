#include <iostream>
using namespace std;
#include "LinkList.h"

//查找第i个元素
status ListFind(LinkList L, int i, ElemType& elem)
{
    if (i < 1)                  //判断i是否合理
    {
        return ERROR;
    }
    ListNode* p = L->next;
    int j = 1;
    while (j != i && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (j == i)                 //如果是由于j=i退出循环，那就是找到了这个元素
    {
        elem = p->data;
        return OK;
    }
    else                        //由于找到最后一个结点退出，就是没有找到
    {
        return ERROR;
    }
}

int ListLocateIndex(LinkList L, ElemType elem)
{
    int i = 1;
    ListNode* p = L->next;
    while (p && p->data != elem)
    {
        p = p->next;
        i++;
    }
    if (!p)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

ListNode* ListLocatePosition(LinkList L, ElemType elem)
{
    ListNode* p = L->next;
    while (p && p->data != elem)
    {
        p = p->next;
    }
    return p;
}

status ListInsert(LinkList& L, int i, ElemType elem)
{
    if (i < 1)                          //插入位置小于1，不正确
    {
        return ERROR;
    }
    ListNode* p = L;
    int j = 0;
    while (p && j != i-1)               //查找第i-1个元素的位置，从头结点开始
    {
        p = p->next;
        j++;
    }
    if (p)                              //如果查到了这个元素，即结点地址不为空
    {
        ListNode* s = new ListNode;
        s->data = elem;
        s->next = p->next;
        p->next = s;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

status ListDelete(LinkList& L, int i, ElemType& elem)
{
    if (i < 1)                          //删除位置小于1，不正确
    {
        return ERROR;
    }
    int j = 0;
    ListNode* p = L;
    while (j != i-1 && p->next)    //需要找到第i-1个结点位置，同时下一个结点地址不能为空，即有4个元素，不能删除第五个
    {
        p = p->next;
        j++;
    }
    if (p->next)
    {
        ListNode* q = p->next;
        elem = q->data;
        p->next = q->next;
        delete q;
        return OK;
    }
    else
    {
        return ERROR;
    }
}
