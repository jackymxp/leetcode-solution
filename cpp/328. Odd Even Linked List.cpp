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
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* evenNode = head->next;
        
        ListNode* oddNode = head;
        ListNode* p = head;
        while(p)
        {
            ListNode* pNext = p->next;
            if(pNext)
                p->next = pNext->next;
            p = pNext;
        }
        p = oddNode;
        while(p->next)
            p = p->next;
        p->next = evenNode;
        return oddNode;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6};
    ListNode* l = createList(arr);
    ListNode* res = s.oddEvenList(l);
    cout << res << endl;
}