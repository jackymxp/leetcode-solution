#include "TreeNode.h"
#include <stack>

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
    vector<int> preorder(Node* root) {
        if(!root)
            return {};
        vector<int> res;
        stack<pair<Node*, string> > q;
        q.push(make_pair(root, "go"));
        while(!q.empty())
        {
            auto p = q.top();
            q.pop();
            if(p.second == "print")
                res.push_back(p.first->val);
            else if(p.second == "go")
            {
                vector<Node*> vnode = p.first->children;
                for(int i = vnode.size() - 1; i >=0 ; i--)
                    if(vnode[i])    
                        q.push(make_pair(vnode[i], "go"));
                q.push(make_pair(p.first, "print"));
            }   
            else
            {
                cout << "error !!" << endl;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    Node* root = nullptr;
    auto res = s.preorder(root);
    for(int i : res)
        cout << i << "  ";
    cout << endl;
    return 0;
}