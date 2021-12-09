#include <iostream>
using namespace std;
#include "LinkList.h"

status ListInit(LinkList& L)
{
    L = new ListNode;   //分配一块地方，可以存放一个节点，即头结点，这个节点的地址就是头指针
    L->next = NULL;     //头指针地址指向头结点，将头结点的指针域置空，表示空链表
    return OK;
}

status ListEmpty(LinkList L)
{
    if (L->next == NULL)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//将链表销毁
//从头结点开始删除，但要注意，如果直接删除会丢失指针域，找不到下一个结点地址，因此应该将头指针后移之后再删除
void ListDestroy(LinkList& L)
{
    ListNode* p;
    while (L != NULL)
    {
        p = L;
        L = L->next;    //在删除之前，需要后移头指针，不然就丢失后继节点地址了
        delete p;
    }
}

//将链表清零
//从首元结点开始删除，保留头结点，操作结束后，将头结点指针域置为空
void ListClear(LinkList& L)
{
    ListNode* q = L->next;
    ListNode* p;
    while (q != NULL)
    {
        p = q;
        q = q->next;
        delete p;
    }
    L->next = NULL;
}

//求链表长度
//从首元结点开始计数累加
int ListLength(LinkList L)
{
    int length = 0;
    ListNode* p = L->next;
    while (p)
    {
        p = p->next;
        length++;
    }
    return length;
}

//查找第i个元素
status ListFind(LinkList L, int i, ListElemType& elem)
{
    if (i < 1)                  //判断i是否合理
    {
        return ERROR;
    }
    ListNode* p = L->next;
    int j = 1;
    while (j != i && p != NULL)
    {
        p = p->next;
        j++;
    }
    if (j == i)                 //如果是由于j=i退出循环，那就是找到了这个元素
    {
        elem = p->data;
        return OK;
    }
    else                        //由于找到最后一个结点退出，就是没有找到
    {
        return ERROR;
    }
}

int ListLocateIndex(LinkList L, ListElemType elem)
{
    int i = 1;
    ListNode* p = L->next;
    while (p && p->data != elem)
    {
        p = p->next;
        i++;
    }
    if (!p)
    {
        return 0;
    }
    else
    {
        return i;
    }
}

ListNode* ListLocatePosition(LinkList L, ListElemType elem)
{
    ListNode* p = L->next;
    while (p && p->data != elem)
    {
        p = p->next;
    }
    return p;
}

status ListInsert(LinkList& L, int i, ListElemType elem)
{
    if (i < 1)                          //插入位置小于1，不正确
    {
        return ERROR;
    }
    ListNode* p = L;
    int j = 0;
    while (p && j != i-1)               //查找第i-1个元素的位置，从头结点开始
    {
        p = p->next;
        j++;
    }
    if (p)                              //如果查到了这个元素，即结点地址不为空
    {
        ListNode* s = new ListNode;
        s->data = elem;
        s->next = p->next;
        p->next = s;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

status ListDelete(LinkList& L, int i, ListElemType& elem)
{
    if (i < 1)                          //删除位置小于1，不正确
    {
        return ERROR;
    }
    int j = 0;
    ListNode* p = L;
    while (j != i-1 && p->next)    //需要找到第i-1个结点位置，同时下一个结点地址不能为空，即有4个元素，不能删除第五个
    {
        p = p->next;
        j++;
    }
    if (p->next)
    {
        ListNode* q = p->next;
        elem = q->data;
        p->next = q->next;
        delete q;
        return OK;
    }
    else
    {
        return ERROR;
    }
}

//头插法创建链表
void ListCreateFromHead(LinkList& L, int n)
{
    L = new ListNode;
    L->next = NULL;
    cout << "头插法建立链表：" << endl;
    for (int i = 0; i < n; i++)
    {
        ListNode* p = new ListNode;
        p->next = L->next;
        L->next = p;
        cout << "请输入第：" << i + 1 << "个元素的值" << endl;
        cin >> p->data;
    }
}

//尾插法建立链表，需要使用辅助结点指针，即尾结点指针，始终指向链表最后一个结点位置
void ListCreateFromTail(LinkList& L, int n)
{
    L = new ListNode;
    L->next = NULL;
    ListNode* pTail = L;
    cout << "尾插法建立链表：" << endl;
    for (int i = 0; i < n; i++)
    {
        ListNode* p = new ListNode;
        p->next = NULL;
        pTail->next = p;
        pTail = p;
        cout << "请输入第：" << i + 1 << "个元素的值" << endl;
        cin >> p->data;
    }
}

void ListPrintElem(ListNode* p)
{
    cout << p->data;
    if (!p->next)
    {
        cout << endl;
    }
    else
    {
        cout<<"  ";
    }
}

void ListForEach(LinkList L, ListFunctionType func)
{
    ListNode* p = L->next;
    while (p)
    {
        func(p);
        p = p->next;
    }
}
