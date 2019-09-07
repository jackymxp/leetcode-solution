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
    ListNode* middleNode(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main(int argc, char* argv[])
{
    Solution s;

    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.middleNode(p1) << endl;

    vector<int> arr2 = {1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1};
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;
    
    cout << s.middleNode(p2) << endl;


    return 0;
}