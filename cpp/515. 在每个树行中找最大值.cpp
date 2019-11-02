#include "TreeNode.h"
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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            int max = INT_MIN;
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                max = node->val > max ? node->val : max;
            }
            res.push_back(max);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,3,5,7,9};
    TreeNode* root = sortedArrayToBST(arr);
    vector<int> res = s.largestValues(root);
    for(int& i : res)
        cout << i << "  ";
    return 0;
}