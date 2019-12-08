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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        if(!root)
            return res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            long  sum = 0;
            for(int i = 0; i < len; i++)
            {
                TreeNode* node = q.front();
                q.pop();
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
                sum += node->val;
            }
            double tmp = (double)(sum) / (double)(len);
            res.push_back(tmp);
        }
        return res;
    }
};

int main(void)
{
    string str = "3,9,20,null,null,15,7";
    TreeNode* root = stringToTreeNode(str);
    Solution s;
    auto res = s.averageOfLevels(root);
    for(int i : res)
        cout << i << "  ";
    cout << endl;
}