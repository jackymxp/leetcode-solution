#include <iostream>
#include <vector>
#include <queue>
using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() {}

    Node(int _val, Node* _left, Node* _right, Node* _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return NULL;
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            int len = q.size();
            vector<Node*> tmp;
            for(int i = 0; i < len; i++)
            {
                Node* node = q.front();
                q.pop();
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
                tmp.push_back(node);
            }
            for(int i = 1; i < len; i++)
                tmp[i-1]->next = tmp[i];
        }
        return root;
    }
};

int main(void)
{
    cout << "test successed !" << endl;
    return  0;
}