#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> mapping1;
        map<char, int> mapping2;
        for(char& c : s)
            mapping1[c]++;
        for(char& c : t)
            mapping2[c]++;
        return mapping1 == mapping2;
    }
};

int main(void)
{
    Solution s;
    string s1 = "anagram", t = "nagaram";
    cout << "res = " << s.isAnagram(s1, t) << endl;
    return 0;
}