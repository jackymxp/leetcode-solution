#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.size();
        int left = 0, right = -1;
        int res = 0;
        map<char, int>  mapping;
        while(right+1 < len && left < len)
        {
            if(mapping[s[right+1]] == 0)
            {
                mapping[s[right+1]]++;
                right++;
            }
            else
            {
                mapping[s[left]]--;
                left++;
            }
            res = max(res, right-left+1);
        }
        return res;
    }
};


int main(void)
{
    Solution s;
    string str1 = "abcabcbb";
    cout << str1 << "===" << s.lengthOfLongestSubstring(str1) << endl;;
    
    
    return 0;
}
