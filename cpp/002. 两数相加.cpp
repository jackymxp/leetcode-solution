#include "ListNode.h"

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
#if 0
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        int flag = 0;
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        while(l1 || l2)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;  
            ListNode* node = new ListNode((a+b+flag)%10);
            flag = (a + b + flag) / 10;
            p->next = node;
            p = node;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if(flag)
        {
            ListNode* node = new ListNode(1);
            p->next = node;
        }

        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
        return dummy->next;
#else
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        
        int a = l1 ? l1->val : 0;
        int b = l2 ? l2->val : 0;
        
        ListNode* nextSum = addTwoNumbers(l1->next, l2->next);
        ListNode* res = new ListNode((a+b)%10);
        if((a+b) / 10)
            res->next = addTwoNumbers(new ListNode(1), nextSum);
        else
            res->next = nextSum;
        return res;
#endif
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {9,9,9,9};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;

    vector<int> arr2 = {1};
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;

    
    cout << s.addTwoNumbers(p1, p2) << endl;
    return 0;
}
