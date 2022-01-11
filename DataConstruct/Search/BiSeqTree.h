#pragma once
#include "define.h"

typedef int KeyType;
typedef int InfoType;

typedef struct
{
    KeyType key;
    InfoType info;
}ElemType;

typedef struct BiSeqTreeNode
{
    ElemType data;
    struct BiSeqTreeNode* lchild, * rchild;
}BiSeqTreeNode, * BiSeqTree;

BiSeqTreeNode* BiSeqTreeSearch(BiSeqTree T, KeyType key);
status BiSeqTreeInsert(BiSeqTree& T, ElemType elem);
status BiSeqTreeMidTraverse(BiSeqTree T);
status BiSeqTreeDeleteNode(BiSeqTree& T, KeyType key);
void BiSeqTreeDemo();
