#include "TreeNode.h"
#include <set>
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
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        if(setting.count(k - root->val))
            return true;
        setting.insert(root->val);
        return findTarget(root->left, k) || findTarget(root->right, k);
    }
private:
    set<int> setting;
};

int main(void)
{
    string str = "[5,3,6,2,4,6,null,7]";
    TreeNode* root = stringToTreeNode(str);
    Solution s;
    bool res = s.findTarget(root, 9);
    cout << "res = " << res << endl;
    return 0;
}
