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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head)
            return nullptr;
        ListNode* p = head;
        for(int i = 0; i < k-1 ; i++)
        {
            if(p)
                p = p->next;
            else
                return head;
        }
        ListNode* para = nullptr;
        if(p)
        {
            para = p->next;
            p->next = nullptr;
        }
        else
            return head;
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        head->next = reverseKGroup(para, k);
        return pre;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    cout << s.reverseKGroup(p1, 3) << endl;
    return 0;
}