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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root)
            return false;
        if(dfs(head, root))
            return true;
        return isSubPath(head, root->left) ||
               isSubPath(head, root->right);
    }
private:
    bool dfs(ListNode* head, TreeNode* root)
    {
        if(head == nullptr)
            return true;
        if(root == nullptr)
            return false;
        if(head->val != root->val)
            return false;
        return dfs(head->next, root->left) || 
               dfs(head->next, root->right);
    }
};