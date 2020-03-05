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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(!s)
            return false;
        bool res = isSameTree(s, t);
        if(res) return true;
        return isSubtree(s->left, t) || isSubtree(s->right, t); 
    }
    bool isSameTree(TreeNode* s, TreeNode* t)
    {
        if(!s || !t)
            return s == t;
        if(s->val != t->val)
            return false;
        else
            return isSameTree(s->left, t->left) && isSameTree(s->right, t->right);
        return true;
    }
};