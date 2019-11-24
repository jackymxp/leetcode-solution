#include "ListNode.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#if 1

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        vector<ListNode*> res;
        int len = lengthList(root);
        ListNode* p = root;
        while(k)
        {
            int thisLen = len / k;
            if(len % k)
                thisLen++;
            
            
            ListNode* pHead = p;

            for(int i = 1; i < thisLen && p; i++)
                p = p->next;

            ListNode* pNext = NULL;
            if(p)
            {
                pNext = p->next;
                p->next = NULL;
            }

            res.push_back(pHead);

            len -= thisLen;
            k--;
            p = pNext;
        }
        return res;
    }
private:
    int lengthList(ListNode* root)
    {
        int res = 0;
        while(root)
        {
            res++;
            root = root->next;
        }
        return res;
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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        res.clear();
        int len = lengthList(root);
        splitListToParts(root, len, k);
        return res;
    }
    vector<ListNode*> res;
    void splitListToParts(ListNode* root, int len, int k)
    {
       cout << "len = " << len << "  k = " << k << endl;
        if(k == 0)
        {
            return ;
        }
        if(!root || len == 0)
        {
            for(int i = 0; i < k; i++)
                res.push_back(NULL);
            return ;
        }
        int thisLen = len / k;
        if(len % k)
            thisLen++;
        cout << "len = " << len << "  k = " << k << "thisLen = " << thisLen << endl;
        ListNode* p = root;
        for(int i = 1; i < thisLen; i++)
        {
            p =  p->next;
        }
        ListNode* pNext = p->next;
        p->next = NULL;
        res.push_back(root);
        splitListToParts(pNext, len-thisLen, --k);

    }
    int lengthList(ListNode* root)
    {
        int res = 0;
        while(root)
        {
            res++;
            root = root->next;
        }
        return res;
    }
};
#endif


int main(void)
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7};
    //vector<int> arr = {};
    ListNode* l = createList(arr);
    vector<ListNode*> res = s.splitListToParts(l, 3);

    for(ListNode* p : res)
        cout << p << endl;
    return 0;

}