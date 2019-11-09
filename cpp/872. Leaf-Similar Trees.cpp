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
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> tmp1, tmp2;
        leafSimilar(root1, tmp1);
        leafSimilar(root2, tmp2);
        return tmp1 == tmp2;
    }
    void leafSimilar(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return ;
        if(!root->left && !root->right)
            res.push_back(root->val);
        leafSimilar(root->left, res);
        leafSimilar(root->right, res);
    }
};

int main(void)
{
    Solution s;
    
}