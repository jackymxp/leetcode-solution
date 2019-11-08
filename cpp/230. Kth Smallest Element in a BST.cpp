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
    int kthSmallest(TreeNode* root, int k) {
        kthSmallestCore(root, k);
        return res;
    }
private:
    int res;
    void kthSmallestCore(TreeNode* root, int& k )
    {
        if(!root)
            return ;
        kthSmallestCore(root->left, k);
        
        k--;
        if(k == 0)
            res = root->val;
        
        kthSmallestCore(root->right, k);
    }
};

int main(void)
{
    Solution s;
    vector<int> arr1 = {1, 2, 3, 4, 5, 6};
    TreeNode* root1 = sortedArrayToBST(arr1);
    int res = s.kthSmallest(root1, 2);
    cout << res << endl;
    return 0;
}