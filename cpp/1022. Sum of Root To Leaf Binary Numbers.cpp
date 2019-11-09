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
    int sumRootToLeaf(TreeNode* root) {
        res = 0;
        int tmp = 0;
        sumRootToLeaf(root, tmp);
        return res;
    }
private:
    int res;
    void sumRootToLeaf(TreeNode* root, int& tmp)
    {
        if(!root)
            return ;
        tmp = tmp * 2 + root->val;
        if(!root->left && !root->right)
            res += tmp;
        sumRootToLeaf(root->left, tmp);
        sumRootToLeaf(root->right, tmp);
        tmp /= 2;
    }
};

int main(void)
{
    Solution s;
    TreeNode* _111 = new TreeNode(1);
    TreeNode* _201 = new TreeNode(0);
    TreeNode* _212 = new TreeNode(1);
    TreeNode* _301 = new TreeNode(0);
    TreeNode* _312 = new TreeNode(1);
    TreeNode* _303 = new TreeNode(0);
    TreeNode* _314 = new TreeNode(1);
    TreeNode* root = _111;
    _111->left = _201;
    _111->right = _212;

    _201->left = _301;
    _201->right = _312;

    _212->left = _303;
    _212->right = _314;

    preOrder(root);
    cout << "===============================" << endl;
    int res = s.sumRootToLeaf(root);
    cout << "res = " << res << endl;
}