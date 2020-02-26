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
    int deepestLeavesSum(TreeNode* root) {
        deepestLeavesSum(root, 0);
        return res;
    }
private:
    int maxHeight = 0;
    int res = 0;
    void deepestLeavesSum(TreeNode* root, int level){
        if(!root)
            return ;
        if(!root->left && !root->right)
        {
            if(level > maxHeight){
                maxHeight = level;
                res = 0;
            }
            if(level == maxHeight){
                res += root->val;
            }
        }
        deepestLeavesSum(root->left, level+1);
        deepestLeavesSum(root->right, level+1);
    }
};

int main(int argc, char* argv[])
{
    string str = "[1,2,3,4,5,null,6,7,null,null,null,null,8]";
    auto root = stringToTreeNode(str);
    Solution s;
    int res = s.deepestLeavesSum(root);
    cout << res << endl;
}