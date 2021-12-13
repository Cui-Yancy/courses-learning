#include <iostream>
using namespace std;
#include "LinkList.h"

LinkList OrderedListMerge(LinkList& La, LinkList& Lb)
{
    LinkList Lc = La;
    ListNode* pc = Lc;
    ListNode* pa = La->next;
    ListNode* pb = Lb->next;
    while (pa && pb)
    {
        if (pa->data <= pb->data)
        {
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }
        else
        {
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    delete Lb;
    return Lc;
}

int main()
{
    cout << "hello yancy" << endl;
    LinkList La;
    int length = 0;
    cout << "请输入想要创建的链表长度：" << endl;
    cin >> length;
    ListCreateFromTail(La, length);
    ListForEach(La, ListPrintElem);

    //LinkList Lb;
    //ListCreateFromTail(Lb, 3);
    //ListForEach(Lb, ListPrintElem);
    
    //LinkList Lc;
    //Lc = OrderedListMerge(La, Lb);
    //ListForEach(Lc, ListPrintElem);

    if (ListEmpty(La))
    {
        cout << "链表为空" << endl;
    }
    else
    {
        cout << "链表不为空" << endl;
    }

    cout << "链表长度：" << ListLength(La) << endl;

    //按序号取值
    int elem = 0;
    int pos = 0;
    status ret = ERROR;
    cout << "您想查找第几个元素的值？" << endl;
    cin >> pos;
    ret = ListFind(La, pos, elem);
    if (ret == ERROR)
    {
        cout << "查找第" << pos << "个元素失败" << endl;
    }
    else
    {
        cout << "第" << pos << "个元素：" <<elem << endl;
    }
    
    //按值查找元素
    cout << "请输入查找的元素值：" << endl;
    cin >> elem;
    cout << "值为" << elem << "的元素序号为：";
    cout << ListLocateIndex(La, elem) << endl;
    cout << "值为" << elem << "的元素在内存中的地址为：";
    cout << ListLocatePosition(La, elem) << endl;

    //插入和删除元素
    cout << "请输入想要插入的元素值：" << endl;
    cin >> elem;
    cout << "请输入想要插入的元素位置：" << endl;
    cin >> pos;
    ret = ListInsert(La, pos, elem);
    if (ret == OK)
    {
        cout << "插入元素成功" << endl;
    }
    else
    {
        cout << "插入元素失败" << endl;
    }
    ListForEach(La, ListPrintElem);

    cout << "请输入想要删除的元素位置：" << endl;
    cin >> pos;
    ret = ListDelete(La, pos, elem);
    if (ret == OK)
    {
        cout << "成功删除元素，元素值为：" << elem << endl;
    }
    else
    {
        cout << "删除失败" << endl;
    }
    ListForEach(La, ListPrintElem);

    //清空链表
    cout << "即将清空链表" << endl;
    system("pause");
    ListClear(La);
    ListForEach(La, ListPrintElem);

    cout << "即将销毁链表" << endl;
    system("pause");
    ListDestroy(La);
    ListForEach(La, ListPrintElem);

    system("pause");
    return 0;
}