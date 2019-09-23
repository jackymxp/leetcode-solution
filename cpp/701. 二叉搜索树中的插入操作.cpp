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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root)
            return new TreeNode(val);
        if(root->val > val)
            root->left = insertIntoBST(root->left, val);
        else
            root->right = insertIntoBST(root->right, val);
        return root;
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    TreeNode* b = sortedArrayToBST(arr1);
    b = s.insertIntoBST(b, 100);
    inOrder(b);

}