#include "TreeNode.h"
#include "ListNode.h"


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head)
            return nullptr;
        if(!head->next)
            return new TreeNode(head->val);
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* mid = nullptr;
        //mid slow fast
        while(fast && fast->next)
        {
            fast = fast->next->next;
            mid = slow;
            slow = slow->next;
        }

        cout << "head = " << head <<endl;
        cout << "slow = " << slow <<endl;
        cout << "mid = " << mid << endl;
      //  TreeNode* root = new TreeNode(mid->val);
      //  root->left = sortedListToBST(head);
     //   root->right = sortedListToBST(slow);
     //   return root;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1, 2, 3, 4, 5};
    ListNode* p = createList(arr);
    TreeNode* root = s.sortedListToBST(p);
 //   inOrder(root);
}