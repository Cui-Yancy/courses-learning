#include "SqQueue.h"
#include <iostream>
using namespace std;

status SeQueueInit(SqQueue &Q)
{
    Q.base = new SqQueueElemType[MAXSEQSIZE];
    if(Q.base == NULL)
    {
        return ERROR;
    }
    Q.rear = 0;
    Q.front = 0;
    return OK;
}

int SeQueueLength(SqQueue Q)
{
    return ((Q.rear - Q.front + MAXSEQSIZE) % MAXSEQSIZE);
}

status SeQueueEnter(SqQueue &Q, SqQueueElemType elem)
{
    if(!Q.base)
    {
        return ERROR;
    }
    if((Q.rear+1)%MAXSEQSIZE == Q.front)    //队满
    {
        return ERROR;
    }
    else
    {
        Q.base[Q.rear] = elem;
        Q.rear = (Q.rear + 1) % MAXSEQSIZE;
        return OK;
    }
}

status SeQueueExit(SqQueue &Q, SqQueueElemType &elem)
{
    if(!Q.base)
    {
        return ERROR;
    }
    if(Q.front == Q.rear)   //队列为空
    {
        return ERROR;
    }
    else
    {
        elem = Q.base[Q.front];
        Q.front = (Q.front + 1) % MAXSEQSIZE;
        return OK;
    }
}

status SeQueueGetHead(SqQueue Q, SqQueueElemType &elem)
{
    if(!Q.base)
    {
        return ERROR;
    }
    if(Q.front == Q.rear)
    {
        return ERROR;
    }
    else
    {
        elem = Q.base[Q.front];
        return OK;
    }
}