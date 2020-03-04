class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        rows = board.size();
        assert(rows > 0);
        cols = board[0].size();
        visited = vector<vector<bool>>(rows, vector<bool>(cols, false));
        int index = 0;
        for(int row = 0; row < rows; row++)
        {
            for(int col = 0; col < cols; col++)
            {
                if(exist(board, word, row, col, index))
                    return true;
            }
        }
        return false;
    }

private:
    int rows;
    int cols;
    vector<vector<bool>> visited;
    int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    
    bool inArea(int row, int col)
    {
        return row >= 0 && row < rows && col >= 0 && col < cols;
    }
    
     bool exist(vector<vector<char>>& board, string& word, int row, int col, int index)
     {
         if(index == word.size() - 1)
             return board[row][col] == word[index];
         
         if(board[row][col] == word[index])
         {
            visited[row][col] = true;
             
            for(int i = 0; i < 4; i++)
            {
                 int newrow = row + d[i][0];
                 int newcol = col + d[i][1];
                 if(inArea(newrow, newcol) && visited[newrow][newcol] == false && exist(board, word, newrow, newcol, index+1))
                     return true;
            }
             
            visited[row][col] = false;
         }
         return false;
     }
};
