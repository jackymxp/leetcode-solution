#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        
        
        int row = matrix.size();
        if(row == 0)
            return {};
        int col = matrix[0].size();
        vector<vector<int>> res(row, vector<int>(col, 0));
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        queue<pair<int, int>> q;
        //将值为0的所有点当作是起点，全部添加到队列中
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                if(matrix[i][j] == 0)
                {
                    visited[i][j] = true;
                    q.push(make_pair(i, j));
                }     
            }
        }
        
        while(!q.empty())
        {
            auto tmp = q.front();
            q.pop();
            int x = tmp.first;
            int y = tmp.second;
            for(int i = 0; i < 4; i++)
            {
                int newx = x + dir[i][0];
                int newy = y + dir[i][1];
                if(newx >= 0 && newx < row && newy >=0 && newy < col && visited[newx][newy] == false)
                {
                    visited[newx][newy] = true;
                    q.push(make_pair(newx, newy));
                    res[newx][newy] = res[x][y] + 1;
                }
            }
        }
        return res;
    }
};

int main(void)
{
    vector<vector<int>> src = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};

    Solution s;
    auto res = s.updateMatrix(src);
    for(auto vv : res)
    {
        for(auto v : vv)
        {
            cout << v << "  ";
        }
        cout << endl;
    }
}