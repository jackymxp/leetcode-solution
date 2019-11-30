#include "TreeNode.h"
#include <map>

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
    vector<int> findFrequentTreeSum(TreeNode* root) {
        if(!root)   return {};
        
        helper(root);
        
        map<int, int> mapping;
        for(int& i : tmp)
            mapping[i]++;
        int count = 0;
        for(auto it = mapping.begin(); it != mapping.end(); it++)
        {
            if(it->second > count)
            {
                count = it->second;
                res.clear();
                res.push_back(it->first);
            }
            else if(it->second == count)
            {
                res.push_back(it->first);
            }
            else 
                continue;
        }
        return res;
    }
private:
    vector<int> tmp;
    vector<int> res;
    int helper(TreeNode* root)
    {
        if(!root)
            return 0;
        root->val += (helper(root->left) + helper(root->right));
        tmp.push_back(root->val);
        return root->val;
    }
};

int main(void)
{
    Solution s;
    
    string str = "[3,1,5,0,2,4,6,null,null,null,3]";

    TreeNode* root = stringToTreeNode(str);

    DisTree{root};    
    s.findFrequentTreeSum(root);

}