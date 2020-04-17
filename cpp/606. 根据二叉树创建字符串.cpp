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
    string tree2str(TreeNode* t) {
        if(!t)
            return "";
        string s = to_string(t->val);
        string left = tree2str(t->left);
        string right=  tree2str (t->right);

        if(!t->left && !t->right)
            return s;
        if(!t->right)
            return s + "(" + left + ")";
        
        return s + "(" + left + ")" + "(" + right + ")";
    }
};