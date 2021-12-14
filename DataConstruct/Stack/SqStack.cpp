#include "SqStack.h"
#include <iostream>
using namespace std;

status SqStackInit(SqStack &S)
{
    S.base = new SqStackElemType[MAXSIZE];
    if(S.base==NULL)
    {
        return ERROR;
    }
    S.top = S.base;
    S.stackSize = MAXSIZE;
    return OK;
}

status SqStackEmpty(SqStack S)
{
    if(S.base == S.top)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

int SqStackLength(SqStack S)
{
    return S.top-S.base;
}

status SqStackClear(SqStack &S)
{
    if(S.base)
    {
        S.top = S.base;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

status SqStackDestroy(SqStack &S)
{
    if(S.base)
    {
        delete [] S.base;
        S.base = S.top = NULL;
        S.stackSize = 0;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

status SqStackPush(SqStack &S,SqStackElemType elem)
{
    if(S.base)
    {
        if(S.top - S.base == S.stackSize)
        {
            return ERROR;
        }
        else
        {
            *(S.top) = elem;
            S.top++;
            return OK;
        }
    }
    else
    {
        return ERROR;
    }
}

status SqStackPop(SqStack &S,SqStackElemType &elem)
{
    if(S.base)
    {
        if(S.top == S.base)
        {
            return ERROR;
        }
        else
        {
            S.top--;
            elem = *S.top;
            return OK;
        }
    }
    else
    {
        return ERROR;
    }
}