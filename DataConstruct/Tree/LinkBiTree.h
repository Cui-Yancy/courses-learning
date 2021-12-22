#pragma once
#include "define.h"

typedef int BiTreeElemType;

typedef struct BiNode
{
    BiTreeElemType data;
    struct BiNode *LChild,*RChild;
}BiNode, *BiTree;

status PreOrderTraverse(BiTree T);
status InOrderTraverse(BiTree T);
status PostOrderTraverse(BiTree T);