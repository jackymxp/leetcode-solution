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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next)
            return head;
        
        if(!head->next->next)
        {
            ListNode* retNode = head->next;
            retNode->next = head;
            head->next = nullptr;
            return retNode;
        }
        
        ListNode* p = head->next->next;
        ListNode* next = head->next;
        next->next = head;
        head->next = swapPairs(p);
        return next;
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.swapPairs(p1) << endl;

    return 0;
}