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
class FindElements {
public:
    FindElements(TreeNode* root) {
        preOrder(root, 0);
    }
    
    bool find(int target) {
        for(auto i : tmp)
            if(i == target)
                return true;
        return false;
    }
private:
    vector<int> tmp;
    void preOrder(TreeNode* root, int index)
    {   
        if(!root)
            return;
        root->val = index;
        tmp.push_back(index);
        preOrder(root->left, 2 * index + 1);
        preOrder(root->right, 2 * index + 2);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */