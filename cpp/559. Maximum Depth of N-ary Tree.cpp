#include "TreeNode.h"

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
    int maxDepth(Node* root) {
        if(!root)
            return 0;
        int res = 0;
        for(auto i : root->children)
        res = max(res, maxDepth(i));
        return res+1;
    }
};

int main(void)
{
    Solution s;
    Node* root = nullptr;
    int res = s.maxDepth(root);
    cout << res << endl;
    return 0;

}