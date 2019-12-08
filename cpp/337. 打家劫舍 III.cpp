#include "TreeNode.h"
#include <map>
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
private:
    map<int, int> mapping;
public:
    int rob(TreeNode* root) {
        if(!root)
            return 0;
        if(mapping[root->val])
            return mapping[root->val];
        
        int sum_with_root = root->val;
        if(root->left)
            sum_with_root += (rob(root->left->left) + rob(root->left->right));
        if(root->right)
            sum_with_root += (rob(root->right->right) + rob(root->right->left));
        
        int sum_without_root = 0;
        sum_without_root += (rob(root->left) + rob(root->right));

        mapping[root->val] = max(sum_with_root, sum_without_root);
        return mapping[root->val];
    }
};

int main(void)
{
    string str = "[3,2,3,null,3,null,1]";
    TreeNode* root = stringToTreeNode(str);
    Solution s;
    int res = s.rob(root);
    cout << "res = " << res << endl;
    return 0;
}