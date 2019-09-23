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
private:
    ListNode* mergeList(ListNode* p1, ListNode* p2)
    {
        if(!p1 || !p2)
            return p1 ? p1 : p2;
        if(p1->val < p2->val)
        {
            p1->next = mergeList(p1->next, p2);
            return p1;
        }
        else
        {
            p2->next = mergeList(p1, p2->next);
            return p2;
        }
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        //find mid ListNode
        ListNode* fast = head;
        ListNode* mid = NULL;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            mid = slow;
            slow = slow->next;
        }
        mid->next = NULL;
    
        head = sortList(head);
        slow = sortList(slow);
        
        return mergeList(head, slow);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {3,1,2,6,9};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
   
    cout << s.sortList(p1) << endl;
    return 0;
}