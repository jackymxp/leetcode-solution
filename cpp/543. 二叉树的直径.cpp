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
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        if(!root)
            return res;
        dfs(root);
        return res;
    }
private:
    int res;
    int dfs(TreeNode* root)
    {
        if(!root)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }
};

int main(void)
{
    Solution s;
    string str = "[1,2,3,4,5]";
    TreeNode* root = stringToTreeNode(str);
    int res = s.diameterOfBinaryTree(root);
    cout << res << endl;
}