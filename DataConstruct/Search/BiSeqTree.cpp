#include "BiSeqTree.h"
#include <iostream>
using namespace std;

//二叉排序树查找算法
//返回值为二叉树结点指针
//使用递归方法查找key值
BiSeqTreeNode* BiSeqTreeSearch(BiSeqTree T, KeyType key)
{
    if (!T || T->data.key == key)               //根结点为空，或者key值等于根结点的key值，都返回根结点指针
    {
        return T;
    }
    else if (key > T->data.key)                 //大于根结点就在右子树继续查找
    {
        return BiSeqTreeSearch(T->rchild, key);
    }
    else
    {
        return BiSeqTreeSearch(T->lchild, key);
    }
}

status BiSeqTreeInsert(BiSeqTree& T, ElemType elem)
{
    if (!T)
    {
        T = new BiSeqTreeNode;
        T->data = elem;
        T->lchild = NULL;
        T->rchild = NULL;
        return OK;
    }
    if (elem.key == T->data.key)
    {
        return ERROR;
    }
    else if (elem.key > T->data.key)
    {
        if (T->rchild == NULL)
        {
            BiSeqTreeNode* ptr = new BiSeqTreeNode;
            ptr->data = elem;
            ptr->lchild = NULL;
            ptr->rchild = NULL;
            T->rchild = ptr;
            return OK;
        }
        else
        {
            return BiSeqTreeInsert(T->rchild, elem);
        }
    }
    else
    {
        if (T->lchild == NULL)
        {
            BiSeqTreeNode* ptr = new BiSeqTreeNode;
            ptr->data = elem;
            ptr->lchild = NULL;
            ptr->rchild = NULL;
            T->lchild = ptr;
            return OK;
        }
        else
        {
            return BiSeqTreeInsert(T->lchild, elem);
        }
    }
}

status BiSeqTreeMidTraverse(BiSeqTree T)
{
    if (!T)
    {
        return OK;
    }
    BiSeqTreeMidTraverse(T->lchild);
    cout << T->data.key << " ";
    BiSeqTreeMidTraverse(T->rchild);
    return OK;
}

//删除二叉排序树的结点
//分为三种情况：
//1、删除结点为叶子结点，最简单，直接删除，修改双亲结点指针域
//2、删除结点只存在左子树或者右子树，将子树根结点替换即可
//3、删除结点存在左右子树，需要保持中序遍历序列有序
//      1、将左子树的最大值结点替换
//      2、将右子树的最小值结点替换
status BiSeqTreeDeleteNode(BiSeqTree& T, KeyType key)
{
    BiSeqTreeNode* ptr = BiSeqTreeSearch(T, key);
    if (!ptr)
    {
        return ERROR;
    }
    else if (ptr->lchild == NULL && ptr->rchild == NULL)
    {
        //叶子结点
    }
    else if (ptr->lchild == NULL && ptr->rchild != NULL)
    {
        //只有右子树
    }
    else if (ptr->lchild != NULL && ptr->rchild == NULL)
    {
        //只有左子树
    }
    else
    {
        //存在左右子树
    }
    return OK;
}

void BiSeqTreeDemo()
{
    BiSeqTree T = NULL;
    int n;
    cout << "请输入排序树结点个数" << endl;
    cin >> n;
    cout << "请输入" << n << "个结点关键字序列" << endl;
    KeyType key;
    ElemType elem;
    for (int i = 0; i < n; i++)
    {
        cin >> key;
        elem.key = key;
        BiSeqTreeInsert(T, elem);
    }
    cout << "原始排序序列：" << endl;
    BiSeqTreeMidTraverse(T);
    cout << endl;
    cout << "请输入查找结点key值：" << endl;
    cin >> key;
    BiSeqTreeNode* ptr = BiSeqTreeSearch(T, key);
    if (ptr == NULL)
    {
        cout << "找不到结点" << endl;
    }
    else
    {
        cout << "找到了，结点key值为：" << ptr->data.key << endl;
    }
}
