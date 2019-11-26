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
    int rangeSumBST(TreeNode* root, int L, int R) {
        res = 0;
        if(!root)
            return res;
        inOrder(root, L, R);
        return res;
    }
private:
    int res;
    void inOrder(TreeNode* root, int L, int R)
    {
        if(!root)
            return ;
        inOrder(root->left, L, R);
        
        if(root->val >= L && root->val <= R)
            res += root->val;
        
        inOrder(root->right, L, R);
    }
};

int main(void)
{
    Solution s;
    string str = "[10,5,15,3,7,null,18]";
    int L = 7, R = 15;
    TreeNode* root = stringToTreeNode(str);
    int res = s.rangeSumBST(root, L, R);
    cout << "res = " << res << endl;
}