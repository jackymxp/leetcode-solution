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
    bool isUnivalTree(TreeNode* root) {
        if(!root)
            return false;
        rootvalue = root->val;
        res = true;
        isUnivalTreeCore(root);
        return res;
    }
private:
    int rootvalue;
    int res;
    void isUnivalTreeCore(TreeNode* root)
    {
        if(!root)
            return ;
        if(root->val != rootvalue)
        {
            res = false;
            return;
        }
        isUnivalTreeCore(root->left);
        isUnivalTreeCore(root->right);
    }
};

int main(void)
{
    Solution s;
    return 0;
}