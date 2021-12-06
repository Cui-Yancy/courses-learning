#pragma once

#define FALSE		0
#define TRUE		1
#define OK		0
#define ERROR		1

typedef int ElemType;
typedef int status;

typedef struct ListNode
{
	ElemType data;
	struct ListNode* next;
}ListNode,*LinkList;

status ListDelete(LinkList& L,int i);
