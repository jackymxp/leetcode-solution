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
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0)
            return vector<TreeNode*>();
        return generateTrees(1, n);
    }
private:
    //[left, right] 为区间的树
    vector<TreeNode*> generateTrees(int left, int right)
    {
        if(left > right)
            return {nullptr};
        vector<TreeNode*> res;
        //以 i 为根， 左：[left, i - 1]   右：[i+1, right]
        for(int i = left; i <= right; i++)
        {
            for(auto& leftNode : generateTrees(left, i-1))
            {
                for(auto& rightNode : generateTrees(i+1, right))
                {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftNode;
                    root->right = rightNode;
                    res.push_back(root);
                }
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    auto res = s.generateTrees(3);
    for(auto& node : res)
    {
        preOrder(node);
        cout << endl;
    }
}