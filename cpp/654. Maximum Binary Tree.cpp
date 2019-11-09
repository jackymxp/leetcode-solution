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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return nullptr;
        if(len == 1)
            return new TreeNode(nums[0]);
        int maxindex = 0;
        for(int i = 1; i < len; i++)
        {
            if(nums[maxindex] < nums[i])
                maxindex = i;
        }
        vector<int> left(nums.begin(), nums.begin()+maxindex);
        vector<int> right(nums.begin()+maxindex+1, nums.end());

        TreeNode* root = new TreeNode(nums[maxindex]);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);
        return root;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {3,2,1,6,0,5};
    TreeNode* root = s.constructMaximumBinaryTree(arr);
    preOrder(root);
    return 0;
}