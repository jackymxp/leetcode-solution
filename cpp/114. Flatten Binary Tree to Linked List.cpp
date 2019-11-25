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
    void flatten(TreeNode* root) {
        if(!root)
            return ;
        flatten(root->left);
        flatten(root->right);
        TreeNode* rightTree = root->right;
        root->right = root->left;
        root->left = NULL;
        TreeNode* p = root;
        while(p->right)
            p = p->right;
        p->right = rightTree;
    }
};


int main(void)
{
    Solution s;
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _3 = new TreeNode(3);
    TreeNode* _4 = new TreeNode(4);
    TreeNode* _5 = new TreeNode(5);
    TreeNode* _6 = new TreeNode(6);

    _1->left = _2;
    _1->right = _5;
    _2->left = _3;
    _2->right = _4;
    _5->right = _6;

    TreeNode* root = _1;
    DisTree dt(root);

    s.flatten(root);

    TreeNode* p = root;
    while (p)
    {
        cout << p->val << "--->";
        p = p->right;
    }
    


}