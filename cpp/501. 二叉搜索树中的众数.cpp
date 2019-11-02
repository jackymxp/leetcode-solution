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
    static bool cmp(pair<int, int> a, pair<int, int> b)
    {
        return a.second > b.second;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int> res ;
        if(!root)
            return res;
        inOrder(root);
        map<int, int> mapping;
        for(int i : inRes)
            mapping[i]++;
        vector<pair<int, int>> pvec(mapping.begin(), mapping.end());
        sort(pvec.begin(), pvec.end(), cmp);
        int num = pvec[0].second;
        for(int i = 0; i < pvec.size(); i++)
        {
            if(pvec[i].second == num)
                res.push_back(pvec[i].first);
            else
                break;
        }
        return res;
    }
private:
    vector<int>inRes;
    void inOrder(TreeNode* root)
    {
        if(!root)
            return ;
        inOrder(root->left);
        inRes.push_back(root->val);
        inOrder(root->right);
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {1,2,2,3,3,3,4,4,4,5,5};
    TreeNode* root = sortedArrayToBST(arr);
    vector<int> res = s.findMode(root);
    for(int i : res)
        cout << i << "  ";
    return 0;
}