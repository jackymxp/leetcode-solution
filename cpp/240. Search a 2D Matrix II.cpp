#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if(rows == 0)
            return false;
        int cols = matrix[0].size();
        int up = 0, down = rows - 1;
        int left = 0, right = cols - 1;
        while(up <= down && left <= right)
        {
            if(matrix[up][right] == target)
                return true;
            else if(matrix[up][right] > target)
                right--;
            else
                up++;
        }
        return false;
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> arr = {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
    };
    bool res = s.searchMatrix(arr, 13);
    cout << "res = " << res << endl;

}