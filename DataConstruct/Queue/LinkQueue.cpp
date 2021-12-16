#include "LinkQueue.h"
#include <iostream>
using namespace std;

status LinkQueueInit(LinkQueue& Q)
{
    Q.front = Q.rear = new LinkQueueNode;
    if (!Q.front)
    {
        return ERROR;
    }
    else
    {
        Q.front->next = NULL;
        return OK;
    }
}

status LinkQueueDestroy(LinkQueue& Q)
{
    LinkQueuePtr p = Q.front;
    while (p)
    {
        Q.front = p->next;
        delete p;
        p = Q.front;
    }
}

status LinkQueueEnter(LinkQueue& Q, LinkQueueElemType elem)
{
    if (!Q.front)
    {
        return ERROR;
    }
    LinkQueuePtr p = new LinkQueueNode;
    if (!p)
    {
        return ERROR;
    }
    p->data = elem;
    p->next = NULL;
    Q.rear->next = p;
    Q.rear = p;
    return OK;
}

status LinkQueueExit(LinkQueue& Q, LinkQueueElemType& elem)
{
    if (!Q.front->next)
    {
        return ERROR;
    }
    LinkQueuePtr p = Q.front->next;
    elem = p->data;
    Q.front = p->next;
    if (p == Q.rear)
    {
        Q.rear = Q.front; 
    }
    delete p;
    return OK;
}

status LinkQueueGetHead(LinkQueue& Q, LinkQueueElemType& elem)
{
    if (Q.front == Q.rear)
    {
        return ERROR;
    }
    else
    {
        elem = Q.front->next->data;
        return OK;
    }
}
