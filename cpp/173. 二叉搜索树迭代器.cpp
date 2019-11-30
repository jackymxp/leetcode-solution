#include "TreeNode.h"
#include <stack>

class BSTIterator {
private:
    stack<TreeNode*> st;
void findLeft(TreeNode* root)
{
    while(root != nullptr)
    {
        st.push(root);
        root = root->left;
    }
}
public:
    BSTIterator(TreeNode* root) {
       findLeft(root);          
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* head = st.top();
        st.pop();
        if(head->right)
            findLeft(head->right);
        return head->val;
        
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(st.empty())
            return false;
        return true;
    }
};

int main(void) {
    string str = "[7,3,15,null,null,9,12]";
    TreeNode* root = stringToTreeNode(str);
    BSTIterator s(root);
    DisTree{root};
    cout << s.next() << endl;
    cout << s.next() << endl;
    cout << s.next() << endl;

    cout << "================================" << endl;
    cout << s.hasNext() << endl;    

}