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
status InOrderTraverse_Stack(BiTree T);
status LevelOrderTraverse(BiTree T);
status BiTreeCreate(BiTree &T);
status BiTreeCopy(BiTree T, BiTree &NewT);
int BiTreeDepth(BiTree T);
int BiTreeNodeNum(BiTree T);
int BiTreeLeafNum(BiTree T);
