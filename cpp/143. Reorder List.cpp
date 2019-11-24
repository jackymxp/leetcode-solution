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
    void reorderList(ListNode* head) {
        if(!head)
            return;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* p = head;
        ListNode* q = reverseList(mid);
        while(p && q)
        {
            ListNode* pNext = p->next;
            ListNode* qNext = q->next;
            p->next = q;
            q->next = pNext;
            p = pNext;
            q = qNext;
        }
    }
private:
        ListNode* reverseList(ListNode* head) {
            if(!head || !head->next)
                return head;
            ListNode* p = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return p;
        }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5};
    ListNode* l1 = createList(arr1);
    s.reorderList(l1);
    cout << l1 << endl;
    return 0;
}