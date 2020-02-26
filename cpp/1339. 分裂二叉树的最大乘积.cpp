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
    vector<int> tmp;
     static const int mod = 1e9 + 7;
public:
    int maxProduct(TreeNode* root) {
        long rootsum = postOrderSum(root);
        long res = -1;
        for(int i = 0; i < tmp.size()-1; i++){
            res = max(res, tmp[i] * (rootsum - tmp[i]));
        }
        return res % mod;
    }
    //计算各个node为跟时候的各个节点的和
    long postOrderSum(TreeNode* root)
    {
        if(!root)
            return 0;
        auto res = root->val + postOrderSum(root->left) + postOrderSum(root->right);
        tmp.push_back(res);
        return res;
    }
};

int main(void){
    string str = "[1,null,2,3,4,null,null,5,6]";
    TreeNode* root = stringToTreeNode(str);
    Solution s;
    auto res = s.maxProduct(root);
    cout << res << endl;
}