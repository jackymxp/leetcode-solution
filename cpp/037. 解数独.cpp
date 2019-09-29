#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        bool res = solveSudoku(board, 0);
        return;
    }
private:
    bool checkBoard(vector<vector<char>>& board, int index, char value)
    {
        int row = index / 9;
        int col = index % 9;
        for(int i = 0; i < 9; i++)
            if(board[row][i] == value)
                return false;
        for(int i =0; i < 9; i++)
            if(board[i][col] == value)
                return false; 
        
        int boxrow = row / 3 * 3;
        int boxcol = col / 3 * 3;
        for(int i = boxrow; i < boxrow + 3; i++)
        {
            for(int j = boxcol; j < boxcol + 3; j++)
                if(board[i][j] == value)
                    return false;
        }
        return true;
    }
    bool solveSudoku(vector<vector<char>>& board, int index) {
        if(index > 80)
           return true;
        int row = index / 9;
        int col = index % 9;
        if(board[row][col] == '.')
        {
            //尝试填1 ~ 9 
            for(char i = '1'; i <= '9'; i++)
            {
                if(checkBoard(board, index, i) == true)
                {
                    board[row][col] = i;
                    if(solveSudoku(board, index+1) == true)
                        return true;
                    board[row][col] = '.';
                }
            }
        }
        else
        {
            return solveSudoku(board, index + 1);
        }
        return false;
    }
};

int main(int argc, char* argv[])
{
    Solution s;
    vector<vector<char>> board = 
    {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
    };

    s.solveSudoku(board);

    for(int i = 0; i < 9; i++)
    {
        for(int j = 0; j <9; j++)
            cout << board[i][j] << "  ";
        cout << endl;
    }

    return 0;
}