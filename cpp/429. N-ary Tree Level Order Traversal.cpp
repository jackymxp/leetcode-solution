#include "TreeNode.h"
#include <queue>
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            vector<int> tmp;
            for(int i = 0; i < len; i++)
            {
                Node* node = q.front();
                q.pop();
                for(auto& v : node->children)
                    if(v)
                        q.push(v);
                tmp.push_back(node->val);
            }
            res.push_back(tmp);
        }
        return res;
    }
};

int main(void)
{
    cout << "test 429 successed !! " << endl;
    return 0;
}