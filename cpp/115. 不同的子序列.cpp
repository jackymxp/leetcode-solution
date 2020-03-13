#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        /*
            dp[i][j] s的长度为j, t的长度为i 时，可以组合的结果。 i [0, t.size()], j [0, s.size()]
            当t的长度为0时， 结果为1
            dp[0][0...s.size()] = 1

            1. 当 s[j-1] != t[i-1]，那也就是s的最后一位没有用上 dp[i][j] = dp[i][j-1]
            2. 当 s[j-1] == t[i-1]
            此时的结果应该是，当使用s的最后一位匹配
                当用s的最后一位的时候， dp[i][j] = dp[i][j-1];
                当不用s的最后一位的时候，dp[i][j] = dp[i-1][j-1];

            *    #  b  a  b  g  b  a  g  j
            * #  1  1  1  1  1  1  1  1
            * b  0  1  1  2  2  3  3  3
            * a  0  0  1  1  1  1  4  4
            * g  0  0  0  0  1  1  1  5 
            * 
            * i  
        */

        unsigned long long dp[t.size()+1][s.size()+1] = {0};
        for(int i = 0; i <= s.size(); i++)
            dp[0][i] = 1;
        for(int j = 1; j <= t.size(); j++)
        {
            for(int i = 1; i <= s.size(); i++)
            {
                if(s[i-1] == t[j-1])
                    dp[j][i] = dp[j-1][i-1] + dp[j][i-1];
                else
                    dp[j][i] = dp[j][i-1]; 
            }
        }

        return dp[t.size()][s.size()];
    }
};

int main(void)
{

}