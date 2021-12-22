#include "LinkBiTree.h"
#include <iostream>
using namespace std;

static void visit(BiNode *node)
{
    cout<< node->data <<endl;
}

status PreOrderTraverse(BiTree T)
{
    if(!T)
    {
        return OK;
    }
    else
    {
        visit(T);
        PreOrderTraverse(T->LChild);
        PreOrderTraverse(T->RChild);
    }
}

status InOrderTraverse(BiTree T)
{
    if(!T)
    {
        return OK;
    }
    else
    {
        InOrderTraverse(T->LChild);
        visit(T);
        InOrderTraverse(T->RChild);
    }
}

status PostOrderTraverse(BiTree T)
{
    if(!T)
    {
        return OK;
    }
    else
    {
        PostOrderTraverse(T->LChild);
        PostOrderTraverse(T->RChild);
        visit(T);
    }
}