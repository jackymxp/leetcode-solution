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
    ListNode* partition(ListNode* head, int x) {
        ListNode* beforeHead = new ListNode(0);
        ListNode* be = beforeHead;
        ListNode* afterHead = new ListNode(0);
        ListNode* af = afterHead;

        while(head)
        {
            if(head->val < x)
            {
                be->next = head;
                be = be->next;
            }
            else
            {
                af->next = head;
                af = af->next;
            }
            head = head->next;
        }
        af->next = NULL;
        be->next = afterHead->next;
        ListNode* retNode = beforeHead->next;
        //delete beforeHead;
        //delete afterHead;
        return beforeHead->next;
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,4,3,2,5,2};

    ListNode* p1 = createList(arr1);
    cout << p1 << endl;
    
    cout << s.partition(p1, 3) << endl;
    return 0;
}