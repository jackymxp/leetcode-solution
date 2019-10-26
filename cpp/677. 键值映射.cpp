#include <iostream>
#include <map>
#include <string>

using namespace std;


class MapSum {
private:
    struct Node
    {
        bool isWord;
        int val;
        map<char, Node*> next;
        Node() : isWord(false), val(0){}
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node();
    }
    
    void insert(string key, int val) {
        Node* cur = root;
        for(char c : key)
        {
            if((cur->next).count(c) == 0)
                (cur->next)[c] = new Node();
            cur = (cur->next)[c];
        }
        cur->isWord = true;
        cur->val = val;
    }
    
    int sum(string prefix) {
        Node* cur = root;
        for(char c : prefix)
        {
            if((cur->next).count(c) == 0)
                return 0;
            else
            {
                cur = (cur->next)[c];
            }
        }
        
        //遍历cur为跟节点，加上所有的val
        return sum(cur);
        
        
        
    }
private:
    int sum(Node* node)
    {
        int res = node->val;
        for(auto it = (node->next).begin(); it != (node->next).end(); ++it)
        {
            res += sum((node->next)[it->first]);
        }
        return res;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

int main(void)
{
    MapSum m;
    m.insert("apple", 3);
    cout << m.sum("ap") << endl;
    m.insert("app", 2);
    cout << m.sum("ap") << endl;
}