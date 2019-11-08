#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        vector<string> vstr;
        stringstream ss(str);
        string item;
        while(getline(ss, item, ' '))
        {
            vstr.push_back(item);
        } 
        if(pattern.size() != vstr.size())
            return false;

        map<char, string> mapping1;
        map<string, char> mapping2;

        int len = pattern.size();
        for(int i = 0; i < len; i++)
        {
            char c = pattern[i];
            string s = vstr[i];
            if(mapping1.count(c) == 0 && mapping2.count(s) == 0)
            {
                mapping1[c] = s;
                mapping2[s] = c;
            }
            if(mapping1.count(c) != 0 && mapping2.count(s) == 0)
            {
                return false;
            }
            if(mapping1.count(c) == 0 && mapping2.count(s) != 0)
            {
                return false;
            }
            if(mapping1.count(c) != 0 && mapping2.count(s) != 0)
            {
                if(mapping1[c] != s || mapping2[s] != c)
                    return false;
            }
        }

        for(auto it = mapping1.begin(); it != mapping1.end(); ++it)
            cout << "it->first: " << it->first << "  it->second: " << it->second << endl;

        return true;
    }
};

int main(void)
{
    Solution s;
    string pattern = "abba";
    string str = "dog dog dog dog";
    cout << s.wordPattern(pattern, str) << endl;
}