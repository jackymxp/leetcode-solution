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
vector<unsigned long long> indexV;
public:
    bool isCompleteTree(TreeNode* root) {
        preOrder(root, 0);
        sort(indexV.begin(), indexV.end());
        return indexV[indexV.size()-1] + 1 == indexV.size();
    }
private:
    void preOrder(TreeNode* root, unsigned long long index)
    {
        if(!root)
            return ;
        indexV.push_back(index);
        preOrder(root->left, 2 * index + 1);
        preOrder(root->right, 2 * index + 2);
    }
};

int main(void)
{
    return 0;
}