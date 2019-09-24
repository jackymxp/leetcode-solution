#include "TreeNode.h"
#include "stack"

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        if(!root)
            return res;
        stack<pair<TreeNode*, string>> s;
        s.push(make_pair(root, "go"));
        while(!s.empty()) {
            auto p = s.top();
            s.pop();
            if(p.second == "print")
                res.push_back(p.first->val);
            else
            {
                if(p.first->right) s.push(make_pair(p.first->right, "go"));
                s.push(make_pair(p.first, "print"));
                if(p.first->left) s.push(make_pair(p.first->left, "go"));
            }
        }
        return res;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    TreeNode* root = sortedArrayToBST(arr1);
    vector<int> res = s.inorderTraversal(root);
    for(auto i : res)
        cout << i << " ";
    return 0;
}