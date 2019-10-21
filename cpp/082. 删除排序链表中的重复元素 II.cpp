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
    ListNode* deleteDuplicates(ListNode* head) {
#if 1
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            if(next && next->val == cur->val)
            {
                while(next && next->val == cur->val)
                    next = next->next;
                pre->next = next;
                cur = next;
                continue;
            }
            pre = cur;
            cur = next;
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
#else
        if(!head || !head->next)
            return head;
        int headvalue = head->val;
        if(head->val != head->next->val)
        {
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else
        {
            ListNode* p = head;
            while(p && p->val == headvalue)
                p = p->next;
            return deleteDuplicates(p);
        }
#endif
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,2,3,3,4,4};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.deleteDuplicates(p1) << endl;
    return 0;
}