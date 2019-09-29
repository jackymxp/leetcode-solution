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
        
        // 解法2:递归
        /* 
        if(!l1  || !l2)
            return l1 ? l1 : l2;
        ListNode* head;
        if(l1->val < l2->val)
        {
            l1->next = mergeTwoLists(l1->next, l2);
            head = l1;
        }
        else
        {
            l2->next= mergeTwoLists(l1, l2->next);
            head = l2;
        }
        return head;
        */
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,3,5,7};
    vector<int> arr2 = {2,4,6,8};


    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;
    
    cout << s.mergeTwoLists(p1, p2) << endl;
    return 0;
}