#include "ListNode.h"
#include <stack>
using namespace std;
#if 1
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
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        int flag = 0;
        cout << "=====" << endl;
        ListNode* dy = new ListNode(-1);
        ListNode* retNode = dy;
        while(!s1.empty() || !s2.empty() || flag > 0)
        {
            int a = s1.empty() == true ? 0 : s1.top();
            int b = s2.empty() == true ? 0 : s2.top();
            cout << "a = " << a << "  b = " << b << endl;
            s1.pop(), s2.pop();
            int sum = a + b + flag;
            flag = sum / 10;
            ListNode* newNode = new ListNode(sum % 10);
            dy->next = newNode;
            dy = newNode;
        }
        return retNode->next;
    }
};



#elif 0
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



#else
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
        return reverseList(addTwoNumbers2(reverseList(l1), reverseList(l2)));
    }
private:
    ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) 
    {
        if(!l1 || !l2)
            return l1 ? l1 : l2;
        int sum = l1->val + l2->val;
        ListNode* node = new ListNode(sum % 10);
        ListNode* nextNode = addTwoNumbers2(l1->next, l2->next);
        
        if((sum / 10) == 1)
            node->next = addTwoNumbers2(nextNode, new ListNode(1));
        else
            node->next = nextNode;
        return node;
        
    }
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next)
            return head;
        ListNode* p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};
#endif

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