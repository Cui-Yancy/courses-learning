#pragma once
#include "define.h"

typedef int ListElemType;

typedef struct ListNode {
    ListElemType data;
    struct ListNode* next;
}ListNode, * LinkList;

//简单算法
status ListInit(LinkList& L);   //初始化链表，只含头结点
status ListEmpty(LinkList L);   //判断链表是否为空
void ListDestroy(LinkList& L);  //销毁链表，清空所有结点
void ListClear(LinkList& L);    //将链表置空，留下头结点
int ListLength(LinkList L);     //求链表长度

//进阶算法
status ListFind(LinkList L, int i, ListElemType& elem);         //链表元素存取，取出链表中第i个元素值
int ListLocateIndex(LinkList L, ListElemType elem);             //定位链表元素，按照元素值，查找元素所在位置
ListNode* ListLocatePosition(LinkList L, ListElemType elem);    //定位链表元素，按照元素值，查找所在结点位置
status ListInsert(LinkList& L, int i, ListElemType elem);       //在第i个位置插入元素
status ListDelete(LinkList& L, int i, ListElemType& elem);      //删除第i个元素，并将删除值保存
void ListCreateFromHead(LinkList& L, int n);                //链表初始化，头插法
void ListCreateFromTail(LinkList& L, int n);                //链表初始化，尾插法

typedef void (*ListFunctionType)(ListNode* p);
void ListPrintElem(ListNode* p);
void ListForEach(LinkList L, ListFunctionType func);
