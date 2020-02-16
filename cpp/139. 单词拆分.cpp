#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    bool findStrinVec(const string& s, vector<string>& wordDict)
    {
        for(auto i : wordDict)
            if(i == s)
                return true;
        return false;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        /*
            dp[i] 长度为i的字符串是否满足条件
            i == 0, true;
            dp[i] = true 的前提条件， dp[j] = true and s[j i) in wordDict
        */   
        auto len = s.size();
        vector<int> dp(len+1, false);
        dp[0] = true;
        for(int i = 1; i <= len; i++)
        {
            for(int j = 0; j < i; j++)
            {
                string tmp(s.begin()+j, s.begin()+i);
                if(dp[j] == true && findStrinVec(tmp, wordDict))
                    dp[i] = true;
            }
        }
        return dp[len];
    }
};

int main(void)
{
    Solution s;
    string str = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    bool res = s.wordBreak(str, wordDict);
    cout << res << endl;
}