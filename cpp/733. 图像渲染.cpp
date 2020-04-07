#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int dir[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1},
    };
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int rows = image.size();
        if(rows == 0)
            return image;
        int cols = image[0].size();
        if(image[sr][sc] == newColor)
            return image;

        int backColor = image[sr][sc];
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            image[row][col] = newColor;
            //将周围四个加入队列
            for(int i = 0; i < 4; i++)
            {
                int newRow = row + dir[i][0];
                int newCol = col + dir[i][1];
                if(newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && image[newRow][newCol] == backColor)
                    q.push(make_pair(newRow, newCol));        
            }
        }
        return image;
    }
};



class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc] == newColor)
            return image;
        floodFillCore(image, sr, sc, image[sr][sc], newColor);
        return image;
    }
    void floodFillCore(vector<vector<int>>& image, int sr, int sc, int oldColor, int newColor)
    {
        if(sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size() || image[sr][sc] != oldColor)
            return;
            
        image[sr][sc] = newColor;
        
        floodFillCore(image, sr+1, sc, oldColor, newColor);
        floodFillCore(image, sr-1, sc, oldColor, newColor);
        floodFillCore(image, sr, sc+1, oldColor, newColor);
        floodFillCore(image, sr, sc-1, oldColor, newColor);      
    }
};
int main()
{
    return 0;
}