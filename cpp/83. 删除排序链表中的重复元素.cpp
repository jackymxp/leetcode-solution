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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        while(cur)
        {
            ListNode* next = cur->next;
            if(next && cur->val == next->val)
            {
                while(next && cur->val == next->val)
                    next = next->next;                
                cur->next = next;
            }
            pre = cur;
            cur = next;
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
        /*
        if(!head || !head->next)
            return head;
        int headvalue = head->val;
        if(head->next->val != headvalue)
        {
            head->next = deleteDuplicates(head->next);
        }
        else
        {
            ListNode* p = head;
            while(p && p->val == headvalue)
                p = p->next;
            head->next = deleteDuplicates(p);
        }
        return head;
        */
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