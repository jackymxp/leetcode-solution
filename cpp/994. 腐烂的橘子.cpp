#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int good = 0, bad = 0;
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(grid[row][col] == 1) good++;
                else if(grid[row][col] == 2) bad++;
            }
        }
        if(good == 0)
            return 0;
        if(bad == 0)
            return -1;
        int backup_good = good;
        int t = 0;
        while(good)
        {
            for(int row = 0; row < rows; row++)
            {
                for(int col = 0; col < cols; col++)
                {
                    if(grid[row][col] == 2)
                    {
                        if(row && grid[row-1][col] == 1)    grid[row-1][col] = 3;
                        if(col && grid[row][col-1] == 1)    grid[row][col-1] = 3;
                        if(row != rows - 1 && grid[row+1][col] == 1) grid[row+1][col] = 3;
                        if(col != cols - 1 && grid[row][col+1] == 1) grid[row][col+1] = 3;
                    }
                }
            }

            for(int row = 0; row < rows; row++)
            {
                for(int col = 0; col < cols; col++)
                {
                    if(grid[row][col] == 3) 
                    {
                        grid[row][col] = 2;
                        good--;
                    }
                }
            }
            t++;
            if(backup_good == good)
                return -1;
            backup_good = good;
        }  
        return t;
    }
};


int main(void){
    Solution s;
    vector<vector<int>> grid = {{2,1,1},{1,1,0},{0,1,1}};
    int res = s.orangesRotting(grid);
    cout << res << endl;
}