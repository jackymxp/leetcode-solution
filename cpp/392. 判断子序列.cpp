#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j{0};
        while(i < s.size() && j < t.size())
        {
            if(s[i] == t[j])
                i++;
            j++;
        }
        return i == s.size();
    }
};

int main(void)
{
    Solution s;
    string str1 = "axc";
    string str2 = "ahbgdc";
    bool res = s.isSubsequence(str1, str2);
    cout << res << endl;

}