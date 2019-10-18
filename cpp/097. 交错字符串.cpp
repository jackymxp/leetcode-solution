#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        //用dp[i][j]表示s1的前i元素和s2前j元素是否交错组成s3前i+j元素
        //dp[i][j] = dp[i-1][j] && s1[i-1] == s3[i+j-1] || dp[i][j-1] && s2[j-1] == s3[i+j-1]
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 == 0)
            return s2 == s3;
        if(len2 == 0)
            return s1 == s3;
        if(len1 + len2 != len3)
            return false;
        
        vector<vector<bool> > dp(len1, vector<bool>(len2, false));
        dp[0][0] = true;
        for(int i = 1; i < len1; i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int i = 1; i < len2; i++)
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        for(int i = 1; i < len1; i++)
        {
            for(int j = 1; j < len2; j++)
            {
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) ||  \
                           (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return dp[len1-1][len2-1];
    }
};

int main(void)
{
    Solution s;
    string a1 = "";
    string a2 = "";
    string a3 = "";

    cout << s.isInterleave(a1, a2, a3) << endl;

    return 0;
}