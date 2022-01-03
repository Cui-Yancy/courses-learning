#pragma once
#include "define.h"

typedef int LinkQueueElemType;

typedef struct LinkQueueNode
{
    LinkQueueElemType data;
    struct LinkQueueNode* next;
}LinkQueueNode, * LinkQueuePtr;

typedef struct LinkQueue
{
    LinkQueuePtr front;     //队头指针
    LinkQueuePtr rear;      //队尾指针
}LinkQueue;

status LinkQueueInit(LinkQueue& Q);
bool LinkQueueEmpty(const LinkQueue& Q);
status LinkQueueDestroy(LinkQueue& Q);
status LinkQueueEnter(LinkQueue& Q, LinkQueueElemType elem);
status LinkQueueExit(LinkQueue& Q, LinkQueueElemType& elem);
status LinkQueueGetHead(LinkQueue& Q, LinkQueueElemType& elem);
