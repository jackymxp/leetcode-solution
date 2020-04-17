#include <iostream>
#include <map>
#include <string>
#include "TreeNode.h"

using namespace std;
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
    vector<TreeNode*> res;
    map<string, int> mapping;
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        preOrder(root);
        return res;

    }
    string preOrder(TreeNode* root)
    {
        if(!root)
            return "";
        string str = to_string(root->val) + "," + preOrder(root->left) + "," + preOrder(root->right);
        
        if(mapping[str] == 1)
            res.push_back(root);
        mapping[str]++;
        return str;
    }
};