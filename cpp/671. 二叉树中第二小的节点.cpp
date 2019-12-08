#include "TreeNode.h"
#include <stack>
#include <set>

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
    int findSecondMinimumValue(TreeNode* root) {
        if(!root)
            return -1;
        setting.clear();
        inOrder(root);
        
        if(setting.size() < 2)
            return -1;

        auto it = setting.begin();
        return *(++it);
    }
private:
    set<int> setting;
    void inOrder(TreeNode* root)
    {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        while(1)
        {
            if(cur)
            {
                s.push(cur);
                cur = cur->left;
            }
            else //cur is null
            {
                if(s.empty())
                    break;
                setting.insert(s.top()->val);
                cur = s.top();
                s.pop();
                cur = cur->right;
            }
        }
    }
};

int main(void)
{
    Solution s;

}