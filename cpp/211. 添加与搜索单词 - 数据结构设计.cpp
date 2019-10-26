#include <iostream>
#include <map>
#include <string>

using namespace std;

class WordDictionary {
private:
    struct Node
    {
        bool isWord;
        map<char, Node*> next;
        Node() : isWord(false) {}
    };
    Node* root;
    bool match(Node* node, string word, int index)
    {
        if(index == word.size())
            return node->isWord == true;
        char c = word[index];
        if(c != '.')
        {
            if((node->next).count(c) == 0)
                return false;
            else
                return match((node->next)[c], word, index+1);
        }
        else if(c == '.')
        {
            for(auto it = (node->next).begin(); it != (node->next).end(); ++it)
            {
                if(match((node->next)[it->first], word, index+1) == true)
                    return true;
            }
            return false;
        }
        else
        {
            cout << "gg" << endl;
        }
        return true;
    }
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new Node();     
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        Node* cur = root;
        for(int i = 0; i < word.size(); i++)
        {
            char c = word[i];
            if((cur->next).count(c) == 0)
                (cur->next)[c] = new Node();
            cur = (cur->next)[c];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        return match(root, word, 0);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

int main(void)
{
    WordDictionary w;
    w.addWord("hello");
    w.addWord("world");
    cout << w.search("hexxo") << endl;
    cout << w.search("he...") << endl;
    cout << w.search("world") << endl;
}