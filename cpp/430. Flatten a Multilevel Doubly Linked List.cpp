#include <iostream>

using namespace std;


// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;

    Node() {}

    Node(int _val, Node* _prev, Node* _next, Node* _child) {
        val = _val;
        prev = _prev;
        next = _next;
        child = _child;
    }
};

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)
            return head;
        Node* p = head;
        while(p)
        {
            if(p->child)
            {
                Node* pNext = p->next;
                Node* tmp = flatten(p->child);
                tmp->prev = p;
                p->next = tmp;
                p->child = nullptr;
                while(tmp->next)
                    tmp = tmp->next; 

                if(pNext) 
                    pNext->prev = tmp;
                tmp->next = pNext;
                p = pNext;
            }
            else
            {
                p = p->next;
            }
        }
        return head;
    }
};


int main(void)
{
    return 0;
}