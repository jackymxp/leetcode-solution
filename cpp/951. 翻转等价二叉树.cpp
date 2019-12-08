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
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        if(!root1 || !root2)
            return root1 == root2;
        
        if(root1->val != root2->val)
            return false;
            
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right) )||
                (flipEquiv(root1->right, root2->left) && flipEquiv(root1->left, root2->right));
    }
};

int main(void)
{
    Solution s;
    string str1 = "[1,2,3,4,5,6,null,null,null,7,8]";
    string str2 = "[1,3,2,null,6,4,5,null,null,null,null,8,7]";
    TreeNode* root1 = stringToTreeNode(str1);
    TreeNode* root2 = stringToTreeNode(str2);
    bool res = s.flipEquiv(root1, root2);
    cout << "res = " << res << endl;
}