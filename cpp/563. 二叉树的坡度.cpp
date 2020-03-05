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
    int findTilt(TreeNode* root) {        
        res = 0;
        sumTilt(root);
        return res;
    }
private:
    int sumTilt(TreeNode* root){
        if(!root)
            return 0;
        int left = sumTilt(root->left);
        int right = sumTilt(root->right);
        res += abs(right-left);
        return left+right+root->val;
    }
    int res;
};