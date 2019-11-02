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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == len - 1)
                    res.push_back(node->val);
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,3,5};
    TreeNode* root = sortedArrayToBST(arr);
    vector<int> res = s.rightSideView(root);
    for(int i : res)
        cout << i << "  ";
    cout << endl;
    return 0;
}