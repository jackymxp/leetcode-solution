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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root)
            return {};
        stack<pair<TreeNode*, string>> s;
        s.push(make_pair(root, "go"));
        vector<int> res;
        while(!s.empty())
        {
            pair<TreeNode*, string> p = s.top();
            s.pop();
            if(p.second == "print")
                res.push_back(p.first->val);
            else
            {
                s.push(make_pair(p.first, "print"));
                if(p.first->right)  s.push(make_pair(p.first->right, "go"));
                if(p.first->left)   s.push(make_pair(p.first->left, "go"));  
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
    vector<int> res = s.postorderTraversal(root);
    for(auto i : res)
        cout << i << " ";
    return 0;
}