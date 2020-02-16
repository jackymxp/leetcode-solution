#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check row
        for(int row = 0; row < 9; row++)
        {
            map<char, int> mapping;
            for(int i = 0; i < 9; i++)
            {
                if(board[row][i] == '.')
                    continue;
                if(mapping.count(board[row][i]) == 1)
                    return false;
                mapping[board[row][i]]++;
            }
            for(int i = 0; i < 9; i++)
            {
                if(board[row][i] == '.')
                    continue;
                if(mapping[board[row][i]] >= 2)
                    return false;
            }
        }
        //check col
        for(int col = 0; col < 9; col++)
        {
            map<char, int> mapping;
            for(int i = 0; i < 9; i++)
            {
                if(board[i][col] == '.')
                    continue;
                mapping[board[i][col]]++;
            }
            
            for(int i = 0; i < 9; i++)
            {
                if(board[i][col] == '.')
                    continue;
                if(mapping[board[i][col]] >= 2)
                    return false;
            } 
        }
        //check box
        for(int row = 0; row < 3; row++)
        {
            for(int col = 0; col < 3; col++)
            {
                int row_start = row * 3;
                int col_start = col * 3;
                int row_end = row * 3 + 3;
                int col_end = col * 3 + 3;
                map<char, int> mapping;
                for(int i = row_start; i < row_end; i++)
                {
                    for(int j = col_start; j < col_end; j++)
                    {
                        if(board[i][j] == '.')
                            continue;
                        mapping[board[i][j]]++;
                    }
                }
               for(int i = row_start; i < row_end; i++)
                {
                    for(int j = col_start; j < col_end; j++)
                    {
                        if(board[i][j] == '.')
                            continue;
                        if(mapping[board[i][j]] >= 2)
                            return false;
                    }
                }
                
            }
        }
        return true;        
    }
};


int main(void)
{
    Solution s;
    string board[9][9] = {
    {"5","3",".",".","7",".",".",".","."},
    {"6",".",".","1","9","5",".",".","."},
    {".","9","8",".",".",".",".","6","."},
    {"8",".",".",".","6",".",".",".","3"},
    {"4",".",".","8",".","3",".",".","1"},
    {"7",".",".",".","2",".",".",".","6"},
    {".","6",".",".",".",".","2","8","."},
    {".",".",".","4","1","9",".",".","5"},
    {".",".",".",".","8",".",".","7","9"},
};
}