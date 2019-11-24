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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next)
            return head;
        //为了方便将后面的值插入到最开始的位置
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* p = head;
        
        //1     2    6    4         3           5       7
        //           p    pNext    pNextNext
        //将pNext放到合适的位置
        //1     2    6  ->     3         5           7  
        //           p  ->  pNextNext    
//pre ------>最终应该定位到2的位置，将pNext插入到pre的后面
        //while pre->next->val < pNext->val
            //pre = pre->next;
        //1     2    6  ->     3         5           7
        //      pre  preNext
        //pNext->val  = 4;
        //pre->next = pNext;
        //pNext->next = preNext;
        
        
        //最后不要忘记重置pre = dummy
        while(p && p->next)
        {
            if(p->val < p->next->val)
                p = p->next;
            else
            {
                ListNode* pNext = p->next;
                ListNode* pNextNext = p->next->next;
                p->next = pNextNext;
                while(pre->next->val < pNext->val)
                    pre = pre->next;
                
                ListNode* preNext = pre->next;
                pre->next = pNext;
                pNext->next = preNext;
                
                pre = dummy;
            }
        }
        return dummy->next;
    }
};


int main(void)
{
    Solution s;
    vector<int> arr = {3,1,2,6,7,8,5,4,9,0};
    ListNode* l = createList(arr);
    ListNode* res = s.insertionSortList(l);
    cout << res << endl;
    return 0;
}