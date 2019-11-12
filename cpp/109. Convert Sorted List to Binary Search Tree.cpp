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
        ListNode* mid = head;
        while(fast && fast->next)
        {
            fast = fast->next->next;
            mid = slow;
            slow = slow->next;
        }
        //mid slow
        ListNode* slowNext = slow->next;
        slow->next = nullptr;
        mid->next = nullptr;
        cout << "head = " << head;
        cout << "mid = " << mid;
        cout << "slow = " << slow ;
        TreeNode* root = new TreeNode(slow->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(slowNext);
        return root;
        
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,2,3,4,5,6,7};
    ListNode* list = createList(arr);
    TreeNode* root = s.sortedListToBST(list);
    inOrder(root);
    return 0;
}