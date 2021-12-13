#pragma once
#include "define.h"

typedef int DuListElemType;

typedef struct DuListNode
{
    DuListElemType data;
    struct DuListNode* prior, * next;
}DuListNode, * DuLinkList;

DuListNode* DuListLocate(DuLinkList L, int i);                      //双向链表查找第i个元素的结点位置
status DuListInsert(DuLinkList& L, int i, DuListElemType elem);     //双向链表在第i个位置插入元素
status DuListDelete(DuLinkList& L, int i, DuListElemType& elem);
