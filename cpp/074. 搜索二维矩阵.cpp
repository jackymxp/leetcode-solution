#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0)
            return false;
        int col = matrix[0].size();
        int len = row * col;
        int left = 0, right = len - 1;
        while(left <= right)
        {
            int mid = left + ((right - left) >> 1);
            if(matrix[mid/col][mid%col] == target)
                return true;
            else if(matrix[mid/col][mid%col] > target)
                right = mid - 1;
            else //if(matrix[mid/col][mid%col] < target)
                left = mid + 1;
        }
        return false;
    }
};

int main(void)
{
    Solution s;
    vector<vector<int>> arr = {
    {1,   3,  5,  7},
    {10, 11, 16, 20},
    {23, 30, 34, 50}
    };
    bool res = s.searchMatrix(arr, 11);
    cout << "res = " << res << endl;
    return 0;
}