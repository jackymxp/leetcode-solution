#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    friend ostream& operator<<(ostream& os, TreeNode& l);
};



class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
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


vector<vector<int>> levelOrderBottom(TreeNode* root) {
    vector<vector<int>> res;
    if(!root)
        return res;
    queue<pair<TreeNode*, int>> q;
    q.push(make_pair(root, 0));
    while(!q.empty())
    {
        auto p = q.front();
        q.pop();
        if(res.size() == p.second)
            res.push_back(vector<int>());
        res[p.second].push_back(p.first->val);
        if(p.first->left)   q.push(make_pair(p.first->left, p.second+1));
        if(p.first->right)   q.push(make_pair(p.first->right, p.second+1));
    }
    return res;
}

#endif /* TREE_NODE_H */