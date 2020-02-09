#include <iostream>

using namespace std;

class MyCircularQueue {
private:
    struct ListNode
    {
        ListNode* next;
        ListNode* pre;
        int value;
        ListNode(int val) : next(nullptr), pre(nullptr), value(val){}
    };
    int size;
    int cap ;
    ListNode* head;
    ListNode* tail;
public:
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        cap = k;
        size = 0;
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->pre = head;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(size == cap)
            return false;
        ListNode* node = new ListNode(value);
        tail->pre->next = node;
        node->pre = tail->pre;
        tail->pre = node;
        node->next = tail;
        size++;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(size == 0)
            return false;
        ListNode* deleteNode = head->next;
        head->next = deleteNode->next;
        deleteNode->next->pre = head;
        delete deleteNode;
        size--;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(size == 0)
            return -1;
        return head->next->value;
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(size == 0)
            return -1;
        return tail->pre->value;
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return size == cap;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */


int main(void)
{
    cout << "622 is successful" << endl;
    return 0;
}