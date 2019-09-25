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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int len = preorder.size();
        if(len == 0)
            return NULL;
        int rootvalue = preorder[0];
        TreeNode* root = new TreeNode(rootvalue);
        int pos = 0;
        for(; pos < len; pos++)
            if(preorder[pos] > rootvalue)
                break;
        vector<int> left(preorder.begin()+1, preorder.begin() + pos);
        vector<int> right(preorder.begin() + pos, preorder.end());
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        return root;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr = {8,5,1,7,10,12};
    TreeNode* root = s.bstFromPreorder(arr);
    inOrder(root);
    return 0;
}