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
    LinkList Lb;
    ListCreateFromTail(La, 5);
    ListCreateFromTail(Lb, 3);
    ListForEach(La, ListPrintElem);
    ListForEach(Lb, ListPrintElem);
    system("pause");
    return 0;
}