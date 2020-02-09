#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
    int min3(int x, int y, int z)
    {
        return min(x, min(y, z));
    }
public:
    int minDistance(string word1, string word2) {
        /*
            当word1长度是i， word2长度是j，需要的次数是dp[i][j]

            if word1[i] == word2[j]  //这时候不要任何操作
                dp[i][j] = dp[i-1][j-1]
            else
            {
                1. 替换  dp[i][j] = dp[i-1][j-1] + 1
                2. 插入  dp[i][j] = dp[i-1][j] + 1
                3. 删除  dp[i][j] = dp[i][j-1] + 1
            }
        */
        int len1 = word1.size();
        int len2 = word2.size();
        //int dp[len1+1][len2+1] = {0};
        vector<vector<int>> dp(len1+1, vector<int>(len2+1, 0));

        for(int i = 1; i <= len1; i++)
            dp[i][0] = dp[i-1][0]+1;

        for(int i = 1; i <= len2; i++)
            dp[0][i] = dp[0][i-1]+1;

        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                if(word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = min3(dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1);
            }
        }
        for(int i = 0; i <= len1; i++)
        {
            for(int j = 0; j <= len2; j++)
                cout << dp[i][j] << "  ";
            cout << endl;
        }
        return dp[len1][len2];
    }
};

int main(void)
{
    Solution s;
    string word1 = "horse", word2 = "ros";
    int res = s.minDistance(word1, word2);
    cout << res << endl;
    return 0;
}