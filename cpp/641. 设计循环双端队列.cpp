#include <iostream>

using namespace std;

class MyCircularDeque {
private:
    struct ListNode{
        ListNode* pre;
        ListNode* next;
        int value;
        ListNode(int val) : pre(nullptr), next(nullptr), value(val){}
    };
    int size;
    ListNode* head;
    ListNode* tail;
    int cap;
public:
    /** Initialize your data structure here. Set the size of the deque to be k. */
    MyCircularDeque(int k) {
        cap = k;
        size = 0;
        head = new ListNode(-1);
        tail = new ListNode(-1);
        head->next = tail;
        tail->pre = head;
    }
    
    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    bool insertFront(int value) {
        if(size == cap)
            return false;
        ListNode* node = new ListNode(value);
        head->next->pre = node;
        node->next = head->next;
        head->next = node;
        node->pre = head;
        size++;
        return true;
    }
    
    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    bool insertLast(int value) {
        if(size == cap)
            return false;
        ListNode* node = new ListNode(value);
        tail->pre->next = node;
        node->pre = tail->pre;
        node->next = tail;
        tail->pre = node;
        size++;
        return true;
    }
    
    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    bool deleteFront() {
        if(size == 0)
            return false;
        ListNode* deleteNode = head->next;
        head->next = deleteNode->next;
        deleteNode->next->pre = head;
        delete deleteNode;
        size--;
        return true;
    }
    
    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    bool deleteLast() {
        if(size == 0)
            return false;
        ListNode* deleteNode = tail->pre;
        deleteNode->pre->next = tail;
        tail->pre = deleteNode->pre;
        delete deleteNode;
        size--;
        return true;
    }
    
    /** Get the front item from the deque. */
    int getFront() {
        //assert(size == 0);
        return head->next->value;
    }
    
    /** Get the last item from the deque. */
    int getRear() {
        //assert(size == 0);
        return tail->pre->value;
    }
    
    /** Checks whether the circular deque is empty or not. */
    bool isEmpty() {
        return size == 0;
    }
    
    /** Checks whether the circular deque is full or not. */
    bool isFull() {
        return cap == size;
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */

int main(void)
{
    return 0;
}