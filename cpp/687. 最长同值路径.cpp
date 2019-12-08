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
    int longestUnivaluePath(TreeNode* root) {
        res = 0;
        
        longestUnivaluePathCore(root);
        return res;
    }
private:
    int res;
    //以root为节点的最长的路径
    int longestUnivaluePathCore(TreeNode* root)
    {
        static int level = 0;
        level++;
        if(!root)
            return 0;
        int left = longestUnivaluePathCore(root->left);
        int right = longestUnivaluePathCore(root->right);
        
        int same_left = 0, same_right = 0;
        if(root->left && root->val == root->left->val)
            same_left = left + 1;
        
        if(root->right && root->val == root->right->val)
            same_right = right + 1;
        
        res = max(res, same_left + same_right);
        
        int tmp = max(same_left, same_right);  
        cout << "root->val: " << root->val << "  left: " << left << "  right: " << right << "  same_left: " << same_left << "  same_right: " << same_right << "  tmp = " << tmp << endl;
        return tmp;
    }
};

int main(void)
{
    Solution s;
    string str = "[1,null,1,1,1,1,1,1]";
    TreeNode* root = stringToTreeNode(str);
    //DisTree{root};

    int res = s.longestUnivaluePath(root);

    cout << "res = " << res << endl;
}
