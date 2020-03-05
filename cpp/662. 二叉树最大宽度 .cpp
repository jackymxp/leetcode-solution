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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        deque<pair<TreeNode*, int>> dq;
        dq.push_back(make_pair(root, 0));
        int res = 0;
        while(!dq.empty())
        {
            int size = dq.size();
            auto f = dq.front();
            auto b = dq.back();
            res = max(res, ((b.second-f.second)+1));
            for(int i = 0; i < size; i++)
            {
                auto tmp = dq.front();
                dq.pop_front();
                auto node = tmp.first;
                int val = tmp.second;
                if(node->left)
                    dq.push_back(make_pair(node->left, (2*val-1)));
                if(node->right)
                    dq.push_back(make_pair(node->right, (2*val)));
            }
        }
        return res;
    }
};

