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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next)
            return false;
        ListNode* fast = head;
        ListNode* slow = head;
        do{
            fast = fast->next->next;
            slow = slow->next;
        }while(fast && fast->next && fast != slow);
        if(slow == fast)
            return true;
        if(!fast || !fast->next)
            return false;
        return true;
    }
};

int main(void)
{
    Solution s;



    return 0;
}