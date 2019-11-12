#include <iostream>
#include <unordered_map>

using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mapping;
        return copyRandomList(head, mapping);
    }
private:
    Node* copyRandomList(Node* head, unordered_map<Node*, Node*>& mapping)
    {
        if(!head)
            return nullptr;
        if(mapping.find(head) != mapping.end()) return mapping[head];
        
        Node* cur = new Node(head->val, nullptr, nullptr);
        mapping[head] = cur;
        cur->next = copyRandomList(head->next, mapping);
        cur->random = copyRandomList(head->random, mapping);
        
        return cur;
    }
};

int main(void)
{
    
}