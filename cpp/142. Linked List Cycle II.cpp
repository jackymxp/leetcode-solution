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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next)
            return nullptr;
        ListNode* fast = head;
        ListNode* slow = head;
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast && fast->next && fast != slow);
        if(!fast || !fast->next)
            return nullptr;
        //fast == slow
        while(head != fast)
        {
            head = head->next;
            fast = fast->next;
        }
        return head;
    }
};

int main(void)
{
    Solution s;
    return 0;
}