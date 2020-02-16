#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size();
        if(row == 0 || obstacleGrid[0][0] == 1)
            return 0;
        int col = obstacleGrid[0].size();
        vector<vector<long>> dp(row, vector<long>(col, 0));
        dp[0][0] = 1;
        for(int i  = 1; i < row; i++)
        {
            if(obstacleGrid[i][0] == 0)     dp[i][0] = 1;
            else break;
        }
        for(int i = 1; i < col; i++)
        {
            if(obstacleGrid[0][i] == 0) dp[0][i] = 1;
            else break;
        }
        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i][j-1] + dp[i-1][j];
            }
        }
        return dp[row-1][col-1];
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> arr = {
  {0,0,0},
  {0,1,0},
  {0,0,0}
};
    int res = s.uniquePathsWithObstacles(arr);
    cout << "res = " << res << endl;
}