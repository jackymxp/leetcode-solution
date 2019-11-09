#include "TreeNode.h"
#include <string>
#include <vector>

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
    vector<string> binaryTreePaths(TreeNode* root) {
        vres.clear();
        string str;
        binaryTreePaths(root, str);
        return vres;
    }
private:
    vector<string> vres;
    void binaryTreePaths(TreeNode* root, string& res)
    {
        if(!root)
            return;

            
        if(!root->left && !root->right)
        {
            vres.push_back(res + to_string(root->val));
            return ;
        }
            
        else
        {
            string backup = res;
            res += (to_string(root->val) + "->");
            binaryTreePaths(root->left, res);
            binaryTreePaths(root->right, res); 
            res = backup;
        }
              
    }
};

int main(void)
{
    Solution s;
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _3 = new TreeNode(3);
    TreeNode* _5 = new TreeNode(5);
    _1->left = _2;
    _1->right = _3;
 //   _2->right = _5;

    vector<string> res = s.binaryTreePaths(_1);
    for(string& str : res)
        cout << str << "  " << endl;
    return 0;
}