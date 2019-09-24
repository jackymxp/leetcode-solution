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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len = preorder.size();
        if(len != inorder.size())
            return NULL;
        if(len == 0)
            return nullptr;
        int rootvalue = preorder[0];
        //在中序遍历中找到根得位置
        int posOfRoot = 0;
        for(; posOfRoot < len; posOfRoot++)
            if(inorder[posOfRoot] == rootvalue)
                break;
        cout << posOfRoot << endl;
        vector<int> preleft(preorder.begin() + 1, preorder.begin() + 1 + posOfRoot);
        vector<int> preright(preorder.begin() + posOfRoot + 1, preorder.end());
        vector<int> inleft(inorder.begin(), inorder.begin()+posOfRoot);
        vector<int> inright(inorder.begin()+posOfRoot+1, inorder.end());

        cout << preleft.size() << preright.size() << inleft.size() << inright.size() << endl;

        TreeNode* root = new TreeNode(rootvalue);
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;  
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> preorder = {3,9,20,15,7};
    vector<int> inorder = {9,3,15,20,7};
    TreeNode* root = s.buildTree(preorder, inorder);
    inOrder(root);

}