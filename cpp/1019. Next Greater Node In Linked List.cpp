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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> res;
        if(!head)
            return res;
        vector<int> src;
        ListNode* p = head;
        for(ListNode* p = head; p; p = p->next)
        {
            bool flag = true;
            for(ListNode* q = p->next; q; q = q->next)
            {
                if(q->val > p->val)
                {
                    res.push_back(q->val);
                    flag = false;
                    break;
                }
            }
            if(flag)
                res.push_back(0);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    //vector<int> arr = {2,1,5};
    vector<int> arr = {};
    ListNode* l = createList(arr);
    vector<int> res = s.nextLargerNodes(l);
    for(auto i : res)
        cout << i << "  ";
    cout << endl;
    return 0;
}