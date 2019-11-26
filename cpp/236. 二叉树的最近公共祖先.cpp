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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || p == root || q == root)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left && !right)
            return NULL;
        else if(left && right)
            return root;
        else if(left && !right)
            return left;
        else if(!left && right)
            return right;
        return NULL;
    }
};

int main(void)
{
    Solution s;
    string str = "[3,5,1,6,2,0,8,null,null,7,4]";
    TreeNode* root = stringToTreeNode(str);
    DisTree{root};

    TreeNode* p = root->left;
    TreeNode* q = root->right;
    TreeNode* res = s.lowestCommonAncestor(root, p, q);
    cout << "res = " << res->val << endl;
}