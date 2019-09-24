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
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }
private:
    bool isSymmetric(TreeNode* root1, TreeNode* root2)
    {
        if(!root1 || !root2)
            return root1 == root2;
        if(root1->val != root2->val)
            return false;
        return isSymmetric(root1->left, root2->right) && isSymmetric(root1->right, root2->left);
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root = sortedArrayToBST(arr1);
    bool res = s.isSymmetric(root);
    cout << res << endl;
    return 0;
}