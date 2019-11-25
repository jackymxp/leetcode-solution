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
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSum(root, res);
        return res;
    }
private:
    int maxPathSum(TreeNode* root, int& res)
    {
        if(!root)
            return 0;
        int three = root->val;
        int left = maxPathSum(root->left, res);
        int right = maxPathSum(root->right, res);
        if(left > 0)
            three += left;
        if(right > 0)
            three += right;
        
        res = max(res, three);
        
        int two = root->val;
        if(left > right && left > 0)
            two += left;
        else if(right > left && right > 0)
            two += right;
        return two;
    }
    
};

int main(void)
{
    Solution s;
    string str = "[1,2,3,4,5,6,7]";
    TreeNode* root = stringToTreeNode(str);
    inOrder(root);
    int res = s.maxPathSum(root);
    cout << "res = " << res << endl;
}