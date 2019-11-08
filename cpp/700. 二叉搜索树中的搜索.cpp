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
    TreeNode* searchBST(TreeNode* root, int val) {
#if 0
        if(!root)
            return nullptr;
        if(root->val == val)
            return root;
        else if(root->val > val)
            return searchBST(root->left, val);
        else if(root->val < val)
            return searchBST(root->right, val);
        return nullptr;
#else
        TreeNode* cur = root;
        while(cur)
        {
            if(val == cur->val)
                return cur;
            else if(val < cur->val)
                cur = cur->left;
            else if(val > cur->val)
                cur = cur->right;
        }
        return nullptr;
#endif
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9};
    TreeNode* b = sortedArrayToBST(arr1);
    TreeNode* res = s.searchBST(b, 6);
    cout << *res << endl;
}