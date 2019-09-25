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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(!t1 || !t2)
            return t1 ? t1 : t2;
        t1->val = t1->val + t2->val;
        t2->val = t1->val;
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
        return t1;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root1 = sortedArrayToBST(arr1);
    vector<int> arr2 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root2 = sortedArrayToBST(arr1);

    auto res = s.mergeTrees(root1, root2);
    inOrder(res);
    return 0;
}