#pragma once
#include "define.h"

typedef int DuListElemType;

typedef struct DuListNode
{
    DuListElemType data;
    struct DuListNode* prior, * next;
}DuListNode, * DuLinkList;

DuListNode* DuListLocate(DuLinkList L, int i);                      //˫��������ҵ�i��Ԫ�صĽ��λ��
status DuListInsert(DuLinkList& L, int i, DuListElemType elem);     //˫�������ڵ�i��λ�ò���Ԫ��
status DuListDelete(DuLinkList& L, int i, DuListElemType& elem);
