#include <iostream>
#include <vector>

using namespace std;    

class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m == 1 || n == 1)
            return 1;
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for(int row = 1; row < m; row++)
        {
            for(int col = 1; col < n; col++)
            {
                dp[row][col] = dp[row][col-1] + dp[row-1][col];
            }
        }
        return dp[m-1][n-1];
    }
};


int main(void)
{
    Solution s;
    int res = s.uniquePaths(10, 5);
    cout << res << endl;
}