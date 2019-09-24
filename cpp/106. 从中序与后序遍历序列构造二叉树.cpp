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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int len = inorder.size();
        if(len != postorder.size())
            return NULL;
        if(len == 0)
            return NULL;
        int rootvalue = postorder[len-1];
        int posOfRoot = 0;
        for(; posOfRoot < len; posOfRoot++)
            if(inorder[posOfRoot] == rootvalue)
                break;
        vector<int> inleft(inorder.begin(), inorder.begin() + posOfRoot);
        vector<int> inright(inorder.begin()+posOfRoot+1, inorder.end());
        vector<int> postleft(postorder.begin(), postorder.begin()+posOfRoot);
        vector<int> postright(postorder.begin()+posOfRoot, postorder.end()-1);
        cout << inleft.size() << inright.size() << postleft.size() << postright.size() << endl;
        TreeNode* root = new TreeNode(rootvalue);
        root->left = buildTree(inleft, postleft);
        root->right = buildTree(inright, postright);
        return root;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> inorder = {9,3,15,20,7};
    vector<int> postorder = {9,15,7,20,3};
    TreeNode* root = s.buildTree(inorder, postorder);
    inOrder(root);

}