#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <vector>
#include <ostream>



using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* createList(const vector<int>& arr)
{
    ListNode* dummy = new ListNode(-1);
    ListNode* p = dummy;
    for(int i : arr)
    {
        ListNode* node = new ListNode(i);
        p->next = node;
        p = node;
    }
    ListNode* retNode = dummy->next;
    delete dummy;

    return retNode;
}

ostream& operator<<(ostream& os, ListNode* l)
{
    while(l)
    {
        os << l->val << "-->";
        l = l->next;
    }
    os << "nullptr" << endl;
    return os;
}  



#endif /* _LIST_H_ */