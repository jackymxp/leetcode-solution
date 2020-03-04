#include "TreeNode.h"
#include <sstream>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {

    void serialize(TreeNode* root, string& res)
    {
        if(!root)   return ;
        if(res.size())  res += ',';
        res += to_string(root->val);
        serialize(root->left, res);
        serialize(root->right, res);
        
    }
    TreeNode* deserialize(const vector<int>& vval, int left, int right)
    {
        if(left > right)
            return nullptr;
        int v = vval[left];
        int mid = ++left;
        while(mid <= right && vval[mid] <= v) mid++;
        TreeNode* root = new TreeNode(v);
        root->left = deserialize(vval, left, mid-1);
        root->right = deserialize(vval, mid, right);
        return root;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        serialize(root, res);
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream sstream(data);
        vector<int> vval;
        string s;
        while(getline(sstream, s, ','))
            vval.push_back(stoi(s));
        return deserialize(vval, 0, vval.size()-1);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(void)
{
    Codec s;
    TreeNode* _1 = new TreeNode(1);
    TreeNode* _2 = new TreeNode(2);
    TreeNode* _3 = new TreeNode(3);
    _2->left = _1;
    _2->right = _3;
    string res = s.serialize(_2);
    TreeNode* root = s.deserialize(res);
    cout << res << endl;
    DisTree{root};
}