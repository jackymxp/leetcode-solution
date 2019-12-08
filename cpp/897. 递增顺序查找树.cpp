#include "TreeNode.h"

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
    TreeNode* increasingBST(TreeNode* root) {

        TreeNode* dummy = new TreeNode(-1);
        tmp = dummy;
        dummy->right = root;
        inOrder(root);
        return dummy->right;
    }
private:
    TreeNode* tmp ;
    void inOrder(TreeNode* cur)
    {
        if(!cur)
            return ;
        inOrder(cur->left);
        
        tmp->right = new TreeNode(cur->val);
        tmp = tmp->right;

        inOrder(cur->right);
    }
};

int main(void)
{
    string str = "[5,3,6,2,4,null,8,1,null,null,null,7,9]";
    TreeNode* root = stringToTreeNode(str);
    Solution s;
    TreeNode* res = s.increasingBST(root);
    DisTree{res};
    return 0;
}