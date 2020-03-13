#include <iostream>
#include <vector>

using 

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row == 0)
            return res;
        int col = matrix[0].size();

        int left = 0, right = col-1;
        int up = 0, down = row - 1;
        while(left <= right && up <= down)
        {
            for(int i = left; i <= right; i++)
                res.push_back(matrix[up][i]);
            
            cout << left << "  " << right << "  " << up << "  " << down << endl;
            for(int i = up+1; i <= down; i++)
                res.push_back(matrix[i][right]);
            cout << left << "  " << right << "  " << up << "  " << down << endl;

            if(up != down)
            for(int i = right-1; i >= left; i--)
                res.push_back(matrix[down][i]);
            cout << left << "  " << right << "  " << up << "  " << down << endl;

            if(left != right)
            for(int i = down-1; i > up; i--)
                res.push_back(matrix[i][left]);
            cout << left << "  " << right << "  " << up << "  " << down << endl;

            left++, right--;
            up++, down--;
        }
        return res;
    }
};