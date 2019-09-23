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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return nullptr;
        if(len == 1)
            return new TreeNode(nums[0]);
        
        int rootvalue = nums[len/2];
        
        TreeNode* root = new TreeNode(rootvalue);
        vector<int> leftnums(nums.begin(), nums.begin() + len / 2);
        vector<int> rightnums(nums.begin() + len / 2 + 1, nums.end());
        root->left = sortedArrayToBST(leftnums);
        root->right = sortedArrayToBST(rightnums);
        return root;
    }
};