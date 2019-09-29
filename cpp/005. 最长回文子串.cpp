#include <iostream> 
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len == 0)
            return s;
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int start = 0, end = 0;
        
        for(int i = 0; i < len;i++)
            dp[i][i] = true;
        
        for(int r = 1; r < len; r++)
        {
            for(int l = 0; l < r; l++)
            {
                if(s[r] == s[l] && (r-l == 1 || dp[l+1][r-1]))
                {
                    dp[l][r] = true;
                    if (r-l > end-start)
                    {
                        start = l; end = r;
                    }
                }
            }
        }
        return s.substr(start,end-start+1);
    }
};
int main(void)
{
    Solution s;
    string str = "babad";
    cout << str << "=====" << s.longestPalindrome(str) << endl;
    return 0;
}


