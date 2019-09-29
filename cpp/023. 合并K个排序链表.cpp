#include "list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
       int len = lists.size();
        if(len == 0)
            return nullptr;
        else if(len == 1)
            return lists[0];
        else if(len == 2)
            return mergeTwoLists(lists[0], lists[1]);
        else
        {
            vector<ListNode*> l1(lists.begin(), lists.begin() + len/2);
            vector<ListNode*> l2(lists.begin() + len/2, lists.end());
            return mergeTwoLists(mergeKLists(l1), mergeKLists(l2));
        }
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(!l1  || !l2)
            return l1 ? l1 : l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(l1 && l2)
        {
            p->next = l1->val < l2->val ? l1 : l2;
            l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
            p = p->next;
        }
        p->next = l1 ? l1 : l2;
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};
    vector<int> arr3 = {1,2,5,6};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;
    ListNode* p3 = createList(arr3);
    cout << p3 << endl;
    
    vector<ListNode*> v = {p1, p2, p3};
    cout << s.mergeKLists(v) << endl;
    return 0;
}