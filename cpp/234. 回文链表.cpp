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
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next)
            return true;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = reverseList(slow);
        
        while(newHead)
        {
            if(newHead->val != head->val)
                return false;
            newHead = newHead->next;
            head = head->next;
        }
        return true; 
        
    }
private:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;

        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newHead;
    }        
};


int main(int argc, char* argv[])
{
    Solution s;

    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.isPalindrome(p1) << endl;

    vector<int> arr2 = {1,2,3,4,5,6,7,8,9,9,8,7,6,5,4,3,2,1};
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;
    
    cout << s.isPalindrome(p2) << endl;


    return 0;
}