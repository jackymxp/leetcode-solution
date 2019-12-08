#include "TreeNode.h"
#include <map>
#include <queue>

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
    static bool cmp(pair<pair<int, int>, TreeNode*>& a, pair<pair<int, int>, TreeNode*>& b)
    {
        if(a.first.first != b.first.first)
            return a.first.first < b.first.first;

        if(a.first.second != b.first.second)
            return a.first.second > b.first.second;
        
        return a.second->val < b.second->val;
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<pair<int, int>, TreeNode*>> q;
        pair<int,int> pos = make_pair(0, 0);
        q.push(make_pair(pos, root));
        vector<pair<pair<int, int>, TreeNode*>> tmp;
        while(!q.empty())
        {
            int len = q.size();
            for(int i = 0; i < len ; i++)
            {
                auto p = q.front();
                q.pop();
                auto pos = p.first;
                TreeNode* node = p.second;
                if(node->left)
                    q.push(make_pair(make_pair(pos.first-1, pos.second-1), node->left));
                if(node->right)
                    q.push(make_pair(make_pair(pos.first+1, pos.second-1), node->right));
                tmp.push_back(make_pair(pos, node));
            }
        }
        sort(tmp.begin(), tmp.end(), cmp);

        map<int, vector<int>> mapping;
        for(auto& i : tmp)
        {
            auto pos = i.first;
            TreeNode* node = i.second;
            mapping[pos.first].push_back(node->val);
        }

        vector<vector<int>> res;//(mapping.begin(), mapping.end());
        for(auto it = mapping.begin(); it != mapping.end(); it++)
            res.push_back(it->second);

        return res;

    }
};

int main(void)
{
    Solution s;
    //string str = "[0,2,1,3,null,null,null,4,5,null,7,6,null,10,8,11,9]";
    //string str = "[1,2,3,4,5,6,7]";
    string str = "[3,9,20,null,null,15,7]";
    TreeNode* root = stringToTreeNode(str);
    //DisTree{root};
    auto res = s.verticalTraversal(root);
    for(auto& v : res)
    {
        for(auto& i : v)
            cout << i << "  ";
        cout << endl;
    }
}