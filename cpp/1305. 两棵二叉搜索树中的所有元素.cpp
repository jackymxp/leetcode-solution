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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        inOrder(root1);
        inOrder(root2);
        sort(res.begin(), res.end());
        return res;
    }
private:
    vector<int> res;
    void inOrder(TreeNode* root){
        if(!root)
            return ;
        inOrder(root->left);
        res.push_back(root->val);
        inOrder(root->right);
    }
};


int main(int argc, char* argv[])
{
    string str1 = "[2,1,4]";
    string str2 = "[1,0,3]";
    TreeNode* root1 = stringToTreeNode(str1);
    TreeNode* root2 = stringToTreeNode(str2);
    Solution s;
    auto res = s.getAllElements(root1, root2);
    for(auto i : res)
        cout << i << "   ";
    cout << endl;
    return 0;
}