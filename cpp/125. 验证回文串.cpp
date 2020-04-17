#include <iostream>

using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        string tmp("");
        for(auto c : s){
            if((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
                tmp += tolower(c);
        }
        cout << tmp << endl;
        int left = 0, right = tmp.size()-1;
        while(left < right){
            if(tmp[left] != tmp[right])
                return false;
            left++, right--;
        }
        return true;
    }
};