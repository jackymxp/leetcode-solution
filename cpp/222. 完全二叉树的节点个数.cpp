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
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root = sortedArrayToBST(arr1);
    auto res = s.countNodes(root);
    cout << res << endl;
    return 0;
}