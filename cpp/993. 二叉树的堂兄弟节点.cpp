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
    bool isCousins(TreeNode* root, int x, int y) {
        xx = x;
        yy = y;
        preOrder(root, 0, 0);

        int parx = (xidx-1)/2;
        int pary = (yidx-1)/2;
        return parx != pary && xlev == ylev;
    }
    void preOrder(TreeNode* root, int index, int level)
    {
        if(!root)   return ;
        if(root->val == xx)
            xidx = index, xlev = level;
        if(root->val == yy)
            yidx = index, ylev = level;
        preOrder(root->left, 2 * index + 1, level + 1);
        preOrder(root->right, 2 * index + 2, level + 1);    
    }
private:
    int xidx;
    int yidx;
    int xlev;
    int ylev;
    int xx;
    int yy;

};

int main(void)
{


    return 0;
}