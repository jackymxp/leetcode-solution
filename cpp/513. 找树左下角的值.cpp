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
    int findBottomLeftValue(TreeNode* root) {
        int res = 0;
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
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                if(i == 0)
                    res = node->val;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    cout << s.findBottomLeftValue(root);
    return 0;
}