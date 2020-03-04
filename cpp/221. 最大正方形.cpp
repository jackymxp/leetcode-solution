#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0)
            return 0;
        int col = matrix[0].size();
        //以i, j 为右下顶点得长方形中，正方形得边长
        vector<vector<int>> dp(row, vector<int>(col, 0));
        int maxLen = 0;

        for(int i = 0; i < row; i++){
            if(matrix[i][0] == '1'){
                maxLen = 1;
                dp[i][0] = 1;
            }     
        }

        for(int i = 0; i < col; i++){
            if(matrix[0][i] == '1'){
                maxLen = 1;
                dp[0][i] = 1;
            }
        }

        for(int i = 1; i < row; i++)
        {
            for(int j = 1; j < col; j++)
            {
                if(matrix[i][j] == '0') continue;
                int len1 = dp[i-1][j];
                int len2 = dp[i][j-1];
                int len3 = dp[i-1][j-1];
                dp[i][j] = min(len1, min(len2, len3)) + 1;
                maxLen = max(maxLen, dp[i][j]);
            }
        }
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
                cout << dp[i][j] << "   ";
            cout << endl;
        }
        return maxLen*maxLen;
    }
};