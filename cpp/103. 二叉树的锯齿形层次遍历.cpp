#include "TreeNode.h"
#include <algorithm>
#include <queue>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while(!q.empty())
        {
            auto p = q.front();
            q.pop();
            if(p.second == res.size())
                res.push_back(vector<int>());
            res[p.second].push_back(p.first->val);
            if(p.first->left) q.push(make_pair(p.first->left, p.second+1)); 
            if(p.first->right) q.push(make_pair(p.first->right, p.second+1)); 
        }
        for(int i = 1; i < res.size(); i+=2)
            reverse(res[i].begin(), res[i].end());
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root = sortedArrayToBST(arr1);
    vector<vector<int>> res = s.zigzagLevelOrder(root);
    for(auto v : res)
    {
        for(auto i : v)
            cout << i << " ";
        cout << endl;
    }     
    return 0;
}
