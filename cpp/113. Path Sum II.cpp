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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        res.clear();
        vector<int> tmp;
        pathSum(root, sum, tmp);
        return res;
    }
private:
    vector<vector<int>> res;
    void pathSum(TreeNode* root, int sum, vector<int>& tmp)
    {
        if(!root) return;
        tmp.push_back(root->val);
        if(!root->left && !root->right && root->val == sum)
        {
            res.push_back(tmp);
        }
        pathSum(root->left, sum-root->val, tmp);
        pathSum(root->right, sum-root->val, tmp);
        tmp.pop_back();
    }
};

int main(void)
{
    Solution s;
    TreeNode* _51 = new TreeNode(5);
    TreeNode* _41 = new TreeNode(4);
    TreeNode* _8 = new TreeNode(8);
    TreeNode* _11 = new TreeNode(11);
    TreeNode* _13 = new TreeNode(13);
    TreeNode* _42 = new TreeNode(4);
    TreeNode* _7 = new TreeNode(7);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _52 = new TreeNode(5);
    TreeNode* _1 = new TreeNode(1);
    _51->left = _41;
    _51->right = _8;
    _41->left = _11;
    _11->left = _7;
    _11->right = _2;
    _8->left = _13;
    _8->right = _42;
    _42->left = _52;
    _42->right = _1;
    TreeNode* root = _51;

    preOrder(root);

    cout << "====================" << endl;

    vector<vector<int>> res = s.pathSum(root, 22);
    for(vector<int>& vi : res)
    {
        for (auto& i : vi)
            cout << i << "  ";
        cout << endl;        
    }

}