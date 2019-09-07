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
    ListNode* reverseList(ListNode* head) {
#if 1
        if(!head || !head->next)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
#else
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while(cur){
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
#endif
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.reverseList(p1) << endl;
    return 0;
}