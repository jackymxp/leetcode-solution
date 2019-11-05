#include "TreeNode.h"
#include "TreeNode.h"
#include <queue>
#include <sstream>
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
public:
#if 0
  // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node = q.front();
            q.pop();
            if(node)
            {
                res += to_string(node->val);
                q.push(node->left);
                q.push(node->right);
            }
            else
                res += "n";
            res += " ";
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return NULL;
    }
#else
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root)
            return "#,";
        string res = to_string(root->val) + ",";
        res += serialize(root->left);
        res += serialize(root->right);
        return res;
    }
    

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        string item;
        queue<string>   q;
        while(getline(ss, item, ','))
            q.push(item);
        return helper(q);
    }
private:
    TreeNode* helper(queue<string>& q)
    {
        string val = q.front();
        q.pop();
        if(val == "#")
            return NULL;
        TreeNode* head = new TreeNode(stoi(val));
        head->left = helper(q);
        head->right = helper(q);
        return head;
    }
#endif
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main(void)
{
    Codec s;
    vector<int> arr1 = {1,2,3,4,5,6};
    TreeNode* root1 = sortedArrayToBST(arr1);
    cout << "serialize  =  " << s.serialize(root1) << endl;

    string src = "4,2,1,#,#,3,#,#,6,5,#,#,#,";
    TreeNode* root2 = s.deserialize(src);
    inOrder(root2);
    cout << endl;
    preOrder(root2);
    return 0;

}