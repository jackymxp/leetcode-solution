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
        if(!head)
            return nullptr;
        Node* p = head;
        while(p)
        {
            Node* pClone = new Node(p->val, nullptr, nullptr);
            pClone = p->next;
            p->next = pClone;
            p = p->next->next;
        }
        p = head;
        while(p && p->next)
        {
            if(p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        Node* retNode = head->next;
        p = retNode;
        while(p && p->next)
        {
            Node* pClone = p->next;
            if(pClone)
                p->next = pClone->next,
            p = pClone->next;
        }
        return retNode;
    }
};




class Solution {
public:
    Node* copyRandomList(Node* head) {
        //mapping original node to its copy
        unordered_map<Node*, Node*> created;  
        return helper(head, created);
    }
    
    Node* helper(Node* head, unordered_map<Node*, Node*> & created) {
        if (!head) return nullptr;	
        if (created.find(head) != created.end()) return created[head];	
        Node * curr = new Node(head->val, nullptr, nullptr);
        created[head] = curr;
        curr->next = helper(head->next, created);
        curr->random = helper(head->random, created);
        return curr;
    }
};


int main(void)
{
    
}

