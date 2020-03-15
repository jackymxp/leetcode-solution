#include <iostream>
#include <vector>
#include <stack>
#include <pair>

using namespace std;

class SolutionRe {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();

        int res = 0;
        vector<vector<bool>> visited(row, vector<bool>(col, false));
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                int tmp = maxAreaOfIsland(grid, i, j, visited);
                res = max(tmp, res);
            }
        }
        return res;
    }
    int maxAreaOfIsland(const vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        if(i < 0 || i >= grid.size() || j < 0 || j >= grid[0].size() || visited[i][j] || grid[i][j] == 0)
            return 0;
        visited[i][j] = true;
        int up = maxAreaOfIsland(grid, i+1, j, visited);
        int down = maxAreaOfIsland(grid, i-1, j, visited);
        int left = maxAreaOfIsland(grid, i, j-1, visited);
        int right = maxAreaOfIsland(grid, i, j+1, visited);

        return up+down+left+right+1;
    }
};


class SolutionDFS {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        stack<pair<int, int>> s;
        int res = 0;
        int row = grid.size();
        if(row == 0)
            return 0;
        int col = grid[0].size();
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                s.push(make_pair(i, j));
                int tmp = 0;
                while(!s.empty())
                {
                    auto p = s.top();
                    s.pop();
                    int x = p.first;
                    int y = p.second;
                    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0)
                        continue;
                    tmp++;
                    grid[x][y] = 0;
                    for(int i = 0;  i< 4; i++)
                    {
                        s.push(make_pair(x+dir[i][0], y+dir[i][1]));
                    }
                }
                res = max(tmp, res);
            }
        }
        return res;
    }
};


class SolutionBFS {
    int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int res{0};
        int row(grid.size());
        if(row == 0)
            return 0;
        int col = grid[0].size();

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                queue<pair<int,int>> s;
                int tmp = 0;
                s.push(make_pair(i, j));
                while(!s.empty())
                {
                    auto p = s.front();
                    s.pop();
                    int x = p.first;
                    int y = p.second;
                    if(x < 0 || x >= row || y < 0 || y >= col || grid[x][y] == 0)
                        continue;
                    tmp++;
                    grid[x][y] = 0;
                    for(int i = 0; i < 4; i++)
                    {
                        s.push(make_pair(x+dir[i][0], y+dir[i][1]));
                    }
                }
                res = max(res, tmp);
            }
        }
        return res;
    }
};

int main(void)
{
    vector<vector<int>> grid = {{0,0,1,0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,1,1,0,1,0,0,0,0,0,0,0,0},
    {0,1,0,0,1,1,0,0,1,0,1,0,0},
    {0,1,0,0,1,1,0,0,1,1,1,0,0},
    {0,0,0,0,0,0,0,0,0,0,1,0,0},
    {0,0,0,0,0,0,0,1,1,1,0,0,0},
    {0,0,0,0,0,0,0,1,1,0,0,0,0}};

    SolutionBFS s;
    int res = s.maxAreaOfIsland(grid);
    cout << res << endl;
}