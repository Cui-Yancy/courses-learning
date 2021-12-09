#pragma once

#define OK      0
#define ERROR   1
#define FALSE   0
#define TRUE    1

typedef int ElemType;
typedef int status;

typedef struct ListNode {
    ElemType data;
    struct ListNode* next;
}ListNode, * LinkList;

//���㷨
status ListInit(LinkList& L);   //��ʼ������ֻ��ͷ���
status ListEmpty(LinkList L);   //�ж������Ƿ�Ϊ��
void ListDestroy(LinkList& L);  //��������������н��
void ListClear(LinkList& L);    //�������ÿգ�����ͷ���
int ListLength(LinkList L);     //��������

//�����㷨
status ListFind(LinkList L, int i, ElemType& elem);         //����Ԫ�ش�ȡ��ȡ�������е�i��Ԫ��ֵ
int ListLocateIndex(LinkList L, ElemType elem);             //��λ����Ԫ�أ�����Ԫ��ֵ������Ԫ������λ��
ListNode* ListLocatePosition(LinkList L, ElemType elem);    //��λ����Ԫ�أ�����Ԫ��ֵ���������ڽ��λ��
status ListInsert(LinkList& L, int i, ElemType elem);       //�ڵ�i��λ�ò���Ԫ��
status ListDelete(LinkList& L, int i, ElemType& elem);      //ɾ����i��Ԫ�أ�����ɾ��ֵ����
void ListCreateFromHead(LinkList& L, int n);                //�����ʼ����ͷ�巨
void ListCreateFromTail(LinkList& L, int n);                //�����ʼ����β�巨
