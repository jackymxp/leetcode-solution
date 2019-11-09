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
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root)
            return false;
        if(root->left == nullptr && root->right == nullptr)
            return root->val == sum;
        return hasPathSum(root->left, sum-root->val) || hasPathSum(root->right, sum-root->val);
    }
};

int main(void)
{
    Solution s;
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    _1->left = _2;

    bool res = s.hasPathSum(_1, 1);
    cout << res << endl;

}