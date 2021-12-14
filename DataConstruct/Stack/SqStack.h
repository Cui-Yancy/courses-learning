#pragma once
#include "define.h"

#define MAXSIZE 100

typedef int SqStackElemType;

typedef struct
{
    SqStackElemType *base;
    SqStackElemType *top;
    int stackSize;
}SqStack;

status SqStackInit(SqStack &S);
status SqStackEmpty(SqStack S);
int SqStackLength(SqStack S);
status SqStackClear(SqStack &S);
status SqStackDestroy(SqStack &S);
status SqStackPush(SqStack &S,SqStackElemType elem);
status SqStackPop(SqStack &S,SqStackElemType &elem);