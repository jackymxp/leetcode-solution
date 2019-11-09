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
    TreeNode* insertIntoMaxTree(TreeNode* root, int val) {
        inRes.clear();
        inOrder(root);
        inRes.push_back(val);
        return constructMaximumBinaryTree(inRes);
    }
private:
    vector<int> inRes;
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
    void inOrder(TreeNode* root)
    {
        if(!root)
            return ;
        inOrder(root->left); 
        inRes.push_back(root->val);
        inOrder(root->right);
    }
};

int main(void)
{

}