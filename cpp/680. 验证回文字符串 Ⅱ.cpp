#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size()-1;
        while(l < r)
        {
            if(s[l] != s[r])
            {
                string tmp1(s.begin()+l+1, s.begin()+r+1);
                string tmp2(s.begin()+l, s.begin()+r);
                return isPalindrome(tmp1) || isPalindrome(tmp2);
            }
            l++, r--;   
        }
        return true;
    }
    bool isPalindrome(const string& s)
    {
        int l = 0, r = s.size()-1;
        while(l < r){
            if(s[l] != s[r])
                return false;
            l++, r--;
        }
        return true;
    }
};