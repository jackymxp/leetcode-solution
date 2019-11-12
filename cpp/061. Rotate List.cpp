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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head)
            return nullptr;
        k = k % (lenOfList(head));
        if(k == 0)
            return head;
        ListNode* p = head;
        ListNode* q = head;
        for(int i = 0; i <= k; i++)
            p = p->next;
        while(p)
        {
            p = p->next;
            q = q->next;
        }
        cout << "p = " << p << endl;
        cout << "q = " << q << endl;
        ListNode* qNext = q->next;
        q->next = nullptr;
        q = qNext;
        while(q->next)
            q = q->next;
        q->next = head;
        
        return qNext;
    }
private:
    int lenOfList(ListNode* head)
    {
        int res = 0;
        while(head)
        {
            head = head->next;
            res+=1;
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;

    ListNode* res = s.rotateRight(p1, 5);
    cout << res << endl;
}