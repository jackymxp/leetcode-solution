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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* p = dummy;
        ListNode* q = dummy;
        for(int i = 0; i < n+1; i++)
            p = p->next;
        while(p){
            p = p->next;
            q = q->next;
        }
        ListNode* deleteNode = q->next;
        q->next = deleteNode->next;
        delete deleteNode;
        return dummy->next;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {7,2,4,3};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;

    cout << s.removeNthFromEnd(p1, 4) << endl;
    return 0;
}