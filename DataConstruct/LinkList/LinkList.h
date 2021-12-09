#pragma once
#include "define.h"

typedef int ListElemType;

typedef struct ListNode {
    ListElemType data;
    struct ListNode* next;
}ListNode, * LinkList;

//���㷨
status ListInit(LinkList& L);   //��ʼ������ֻ��ͷ���
status ListEmpty(LinkList L);   //�ж������Ƿ�Ϊ��
void ListDestroy(LinkList& L);  //��������������н��
void ListClear(LinkList& L);    //�������ÿգ�����ͷ���
int ListLength(LinkList L);     //��������

//�����㷨
status ListFind(LinkList L, int i, ListElemType& elem);         //����Ԫ�ش�ȡ��ȡ�������е�i��Ԫ��ֵ
int ListLocateIndex(LinkList L, ListElemType elem);             //��λ����Ԫ�أ�����Ԫ��ֵ������Ԫ������λ��
ListNode* ListLocatePosition(LinkList L, ListElemType elem);    //��λ����Ԫ�أ�����Ԫ��ֵ���������ڽ��λ��
status ListInsert(LinkList& L, int i, ListElemType elem);       //�ڵ�i��λ�ò���Ԫ��
status ListDelete(LinkList& L, int i, ListElemType& elem);      //ɾ����i��Ԫ�أ�����ɾ��ֵ����
void ListCreateFromHead(LinkList& L, int n);                //�����ʼ����ͷ�巨
void ListCreateFromTail(LinkList& L, int n);                //�����ʼ����β�巨

typedef void (*ListFunctionType)(ListNode* p);
void ListPrintElem(ListNode* p);
void ListForEach(LinkList L, ListFunctionType func);
