#pragma once
#include "define.h"

typedef int LinkStackElemType;

typedef struct LinkStackNode
{
    LinkStackElemType data;
    struct LinkStackNode *next;
}LinkStackNode, *LinkStack;

void LinkStackInit(LinkStack &S);
status LinkStackEmpty(LinkStack S);
status LinkStackPush(LinkStack &S, LinkStackElemType elem);
status LinkStackPop(LinkStack &S, LinkStackElemType &elem);
status LinkStackGetTop(LinkStack &S, LinkStackElemType &elem);
