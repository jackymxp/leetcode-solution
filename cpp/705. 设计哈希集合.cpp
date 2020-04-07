class MyHashSet {
    int hash[1000000];
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        for(int i = 0; i < 1000000; i++)
            hash[i] = -1;
    }
    
    void add(int key) {
        hash[key] = 1;
    }
    
    void remove(int key) {
        hash[key] = -1;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key] == 1;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */