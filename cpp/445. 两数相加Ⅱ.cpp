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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        ListNode* dummy = new ListNode(-1);
        ListNode* p = dummy;
        int flag = 0;
        while(l1 || l2)
        {
            int a = l1 ? l1->val : 0;
            int b = l2 ? l2->val : 0;
            ListNode* node = new ListNode((a+b+flag)%10);
            flag = (flag + a + b) / 10;
            p->next = node;
            p = node;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        if(flag)
        {
            p->next = new ListNode(1);
        }
        return reverseList(dummy->next);
    }
private:
    ListNode* reverseList(ListNode* p)
    {
        ListNode* pre = nullptr;
        ListNode* cur = p;
        while(cur)
        {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {7,2,4,3};
    vector<int> arr2 = {5,6,4};


    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    ListNode* p2 = createList(arr2);
    cout << p2 << endl;
    
    cout << s.addTwoNumbers(p1, p2) << endl;
    return 0;
}