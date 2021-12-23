#include "LinkBiTree.h"
#include <iostream>
#include "LinkStack.h"
#include "SqQueue.h"

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

status InOrderTraverse_Stack(BiTree T)
{
    BiTree p;
    p = T;
    LinkStack S;
    LinkStackInit(S);

    while(p || !LinkStackEmpty(S))
    {
        if(p)
        {
            LinkStackPush(S,p);
            p = p->LChild;
        }
        else
        {
            BiTree q;
            LinkStackPop(S,q);
            cout<< q->data <<endl;
            p = q->RChild;
        }
    }

    return OK;
}

status LevelOrderTraverse(BiTree T)
{
    SqQueue Q;
    SeQueueInit(Q);
    SeQueueEnter(Q,T);
    BiNode *p;
    while(SeQueueLength(Q))
    {
        SeQueueExit(Q,p);
        cout<< p->data <<endl;
        if(p->LChild)
        {
            SeQueueEnter(Q,p->LChild);
        }
        if(p->RChild)
        {
            SeQueueEnter(Q,p->RChild);
        }
    }
}

status BiTreeCreate(BiTree &T)
{
    char ch;
    cin >> ch;
    if(ch == '#')
    {
        T = NULL;
    }
    else
    {
        T = new BiNode;
        if(!T)
        {
            exit(OVERFLOW);
        }
        T->data = ch;
        BiTreeCreate(T->LChild);
        BiTreeCreate(T->RChild);
    }
    return OK;
}

status BiTreeCopy(BiTree T, BiTree &NewT)
{
    if(!T)
    {
        NewT = NULL;
        return OK;
    }
    else
    {
        NewT = new BiNode;
        NewT->data = T->data;
        BiTreeCopy(T->LChild,NewT->LChild);
        BiTreeCopy(T->RChild,NewT->RChild);
    }
}

int BiTreeDepth(BiTree T)
{
    int left,right;
    if(!T)
    {
        return 0;
    }
    else
    {
        left = BiTreeDepth(T->LChild);
        right = BiTreeDepth(T->RChild);
        return ((left>right)?left:right)+1;
    }
}

int BiTreeNodeNum(BiTree T)
{
    int left,right;
    if(!T)
    {
        return 0;
    }
    else
    {
        left = BiTreeNodeNum(T->LChild);
        right = BiTreeNodeNum(T->RChild);
        return left+right+1;
    }
}

int BiTreeLeafNum(BiTree T)
{
    if(!T)
    {
        return 0;
    }
    else
    {
        if(T->LChild == NULL && T->RChild == NULL)
        {
            return 1;
        }
        else
        {
            return BiTreeLeafNum(T->LChild)+BiTreeLeafNum(T->RChild);
        }
    }
}
