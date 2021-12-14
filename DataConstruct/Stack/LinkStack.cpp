#include "LinkStack.h"
#include <iostream>
using namespace std;

void LinkStackInit(LinkStack &S)
{
    S = NULL;
}

status LinkStackEmpty(LinkStack S)
{
    if(S == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

status LinkStackPush(LinkStack &S, LinkStackElemType elem)
{
    LinkStackNode *node = new LinkStackNode;
    node->data = elem;
    node->next = S;
    S = node;
    return OK;
}

status LinkStackPop(LinkStack &S, LinkStackElemType &elem)
{
    if(S==NULL)
    {
        return ERROR;
    }
    else
    {
        elem = S->data;
        LinkStackNode *p = S;
        S = S->next;
        delete p;
        return OK;
    }
}

status LinkStackGetTop(LinkStack &S, LinkStackElemType &elem)
{
    if(S==NULL)
    {
        return ERROR;
    }
    else
    {
        elem = S->data;
        return OK;
    }
}