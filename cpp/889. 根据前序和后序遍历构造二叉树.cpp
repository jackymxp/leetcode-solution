#include "TreeNode.h"
#include <cassert>

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
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        int len = pre.size();
        assert(len == post.size());
        if(len == 0)
            return nullptr;
        else if(len == 1)
        {
            assert(pre[0] == post[0]);
            return new TreeNode(pre[0]);
        }
        int rootval = pre[0];
        int pos = 0;
        for(pos = 0; pos < len; pos++)
            if(post[pos] == pre[1])
                break;
        TreeNode* root = new TreeNode(rootval);

        vector<int> leftpre(pre.begin()+1, pre.begin()+2+pos);
        vector<int> leftpost(post.begin(), post.begin()+pos+1);
        vector<int> rightpre(pre.begin()+2+pos, pre.end());
        vector<int> rightpost(post.begin()+pos+1, post.end()-1);

        root->left = constructFromPrePost(leftpre, leftpost);
        root->right = constructFromPrePost(rightpre, rightpost);
        return root;
    }
};

int main(void)
{
    Solution s;
    vector<int> pre = {1,2,4,5,3,6,7}, post = {4,5,2,6,7,3,1};
    TreeNode* root = s.constructFromPrePost(pre, post);
    DisTree{root};
}