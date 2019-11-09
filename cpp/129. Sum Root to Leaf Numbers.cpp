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
    int sumNumbers(TreeNode* root) {
        res = 0;
        int tmp = 0;
        sumNumbers(root, tmp);
        return res;
    }
    
private:
    int res;
    void sumNumbers(TreeNode* root, int& tmp)
    {
        if(!root)
            return;
        tmp = tmp * 10 + root->val;
        if(!root->left && !root->right)
        {
            res += tmp;
        }
        sumNumbers(root->left, tmp);
        sumNumbers(root->right, tmp);   
        tmp/=10;
    }
};

int main(void)
{
    Solution s;
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _3 = new TreeNode(3);
    _1->left = _2;
    _1->right = _3;
    TreeNode* root = _1;
    int res = s.sumNumbers(root);
    cout << "res = " << res << endl;
    return 0;
}