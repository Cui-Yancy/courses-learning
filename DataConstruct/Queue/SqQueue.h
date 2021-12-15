#pragma once
#include "define.h"

#define MAXSEQSIZE  100
typedef int SqQueueElemType;
typedef struct
{
    SqQueueElemType *base;
    int front;
    int rear;
}SqQueue;

status SeQueueInit(SqQueue &Q);
status SeQueueEnter(SqQueue &Q, SqQueueElemType elem);
int SeQueueLength(SqQueue Q);       //返回队列中的元素个数
status SeQueueExit(SqQueue &Q, SqQueueElemType &elem);
status SeQueueGetHead(SqQueue Q, SqQueueElemType &elem);   //获取队头元素和出队不一样，不改变队列内容
