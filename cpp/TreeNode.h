#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    friend ostream& operator<<(ostream& os, TreeNode& l);
};

ostream& operator<<(ostream& os, TreeNode& l)
{
    os << l.val ;
    return os;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
    int len = nums.size();
    if(len == 0)
        return NULL;
    int mid = len / 2;
    vector<int> left(nums.begin(), nums.begin() + mid);
    vector<int> right(nums.begin()+mid+1, nums.end());
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = sortedArrayToBST(left);
    root->right = sortedArrayToBST(right);
    return root;
}



void preOrder(TreeNode* root)
{
    if(!root)
        return ;
    cout << root->val << "-->" ;
    preOrder(root->left);
    preOrder(root->right); 
}

void inOrder(TreeNode* root)
{
    if(!root)
        return ;
    inOrder(root->left); 
    cout << root->val << "-->" ;
    inOrder(root->right);
}

void postOrder(TreeNode* root)
{
    if(!root)
        return ;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->val << "-->" ;
}

#endif /* TREE_NODE_H */