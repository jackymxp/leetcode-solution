#include <iostream>
#include <map>
#include <string>

using namespace std;

class Trie {
private:
    struct Node
    {
        bool isWord;
        map<char, Node*> next;
        Node()
        {
            isWord = false;
        }
    };
    Node* root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if((cur->next).count(c) == 0)
                (cur->next)[c] = new Node();
            cur = (cur->next)[c];
        }
        if(cur->isWord == false)
            cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if((cur->next).count(c) == 0)
                return false;
            cur = (cur->next)[c];
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* cur = root;
        for(int i = 0; i < prefix.size(); i++)
        {
            char c = prefix[i];
            if((cur->next).count(c) == 0)
                return false;
            cur = (cur->next)[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    Trie t;
    t.insert("hello");
    cout << t.search("he") << endl;
    cout << t.search("hello") << endl;
    cout << t.startsWith("hello") << endl;
    cout << t.startsWith("he") << endl;
}