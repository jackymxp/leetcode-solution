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
    int res = 0;
public:
    int sumEvenGrandparent(TreeNode* root) {
       sumEvenGrandparentCore(root);
        return res;
    }

   void sumEvenGrandparentCore(TreeNode* root)
   {
        if(!root)   return ;
        if(root->val % 2 == 0){
            if(root->left && root->left->left)  res += root->left->left->val;
            if(root->left && root->left->right) res += root->left->right->val;
            if(root->right && root->right->left)    res += root->right->left->val;
            if(root->right && root->right->right)   res += root->right->right->val;
        }
        sumEvenGrandparentCore(root->left);
        sumEvenGrandparentCore(root->right);
   } 
};

int main(void)
{
    Solution s;
    string str = "[6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]";
    auto root = stringToTreeNode(str);
    int res = s.sumEvenGrandparent(root);
    cout << res << endl;
}