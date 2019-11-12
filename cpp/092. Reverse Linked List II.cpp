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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(!head)
            return nullptr;
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for(int i = 0; i < m-1; i++)
            p = p->next;
        for(int i = 0; i < n; i++)
            q = q->next;
        ListNode* pNext = p->next;
        ListNode* qNext = q->next;
        p->next = nullptr;
        q->next = nullptr;
        ListNode* revP = reverseList(pNext);
        p->next = revP;
        pNext->next = qNext;
        return dummy->next;
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
    vector<int> arr = {3,5};
    ListNode* p = createList(arr);
    cout << p << endl;
    ListNode* res = s.reverseBetween(p, 1, 2);
    cout << res << endl;
    return 0;
}