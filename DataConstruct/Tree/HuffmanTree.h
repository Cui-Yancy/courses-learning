#pragma once

typedef struct
{
    float weight;
    int parent, lchild, rchild;
}HuffmanTreeNode, * HuffmanTree;


void HuffmanTreeCreate(HuffmanTree& HT, int n);
