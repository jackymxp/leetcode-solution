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
    ListNode* removeElements(ListNode* head, int val) {
#if 1
        if(!head || (!head->next && head->val != val))
            return head;
        if(head->val != val)
        {
            head->next = removeElements(head->next, val);
            return head;
        }
        else
        {
            head = removeElements(head->next, val);
            return head;
        }
        
#else
        if(!head)
            return head;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = head;
        while(cur)
        {
            if(cur && cur->val == val)
            {
                while(cur && cur->val == val)
                    cur = cur->next;
                pre->next = cur;
            }
            pre = cur; 
            cur = cur ? cur->next : nullptr;
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
#endif
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,3,6,6,4,5,6,7,8,9,6};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.removeElements(p1, 6) << endl;
    return 0;
}