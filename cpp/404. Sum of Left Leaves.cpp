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
    int sumOfLeftLeaves(TreeNode* root) {
        res = 0;
        sumOfLeftLeavesCore(root);
        return res;
    }
private:
    int res = 0;
    void sumOfLeftLeavesCore(TreeNode* root)
    {
        if(!root)
            return ;
        if(root->left && !root->left->left && !root->left->right)
        {
            res += root->left->val;
            cout << "res = " << res << endl;
        }
            
        sumOfLeftLeavesCore(root->left);
        sumOfLeftLeavesCore(root->right);
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    TreeNode* root1 = sortedArrayToBST(arr1);
    int res = s.sumOfLeftLeaves(root1);
    cout << res << endl;
    return 0;
}