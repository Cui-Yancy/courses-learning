#pragma once

#define OK      0
#define ERROR   1
#define TRUE    1
#define FALSE   0

typedef int ElemType;
typedef int status;

typedef struct ListNode {
    ElemType data;
    struct ListNode* next;
}ListNode, * LinkList;

status ListFind(LinkList L, int i, ElemType& elem);
int ListLocateIndex(LinkList L, ElemType elem);
ListNode* ListLocatePosition(LinkList L, ElemType elem);
status ListInsert(LinkList& L, int i, ElemType elem);
status ListDelete(LinkList& L, int i, ElemType& elem);
