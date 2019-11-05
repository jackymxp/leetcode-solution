#include <iostream>
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
        vector<int> left;
        vector<int> right;
        dfs(root1, left);
        dfs(root2, right);
        return left == right;
    }
private:
    void dfs(TreeNode* root, vector<int>& res)
    {
        if(!root)
            return ;
        if(!root->left && !root->right)
            res.push_back(root->val);
        dfs(root->left, res);
        dfs(root->right, res);
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5,6};
    vector<int> arr2 = {1,2,3,4,5,6};
    TreeNode* root1 = sortedArrayToBST(arr1);
    TreeNode* root2 = sortedArrayToBST(arr2);
    cout << s.leafSimilar(root1, root2) << endl;
}