#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        res.clear();
        
        col = vector<bool>(n, false);
        diag1 = vector<bool>(2 * n - 1, false);
        diag2 = vector<bool>(2 * n - 1, false);
        vector<int> row;
        solveNQueens(n, 0, row);
        return res;
    }

private:
    vector<vector<string>> res;
    vector<bool> col, diag1, diag2;
    //在n皇后问题中， 尝试摆放第 index 行位置的皇后
    void solveNQueens(int n, int index, vector<int>& row)
    {
        if(index == n)
        {
            res.push_back(generateBoard(n, row));
            return ;
        }
        
        for(int i = 0; i < n; i++)
        {
            //尝试将第index行的皇后摆放在i列
            if(col[i] == false && !diag1[index+i] && !diag2[i-index+n-1])
            {
                row.push_back(i);
                col[i] = true;
                diag1[index+i] = true;
                diag2[i-index+n-1] = true;
                
                solveNQueens(n, index + 1, row);
                
                row.pop_back();
                col[i] = false;
                diag1[index+i] = false;
                diag2[i-index+n-1] = false;
            }
        }
        
    }
    vector<string> generateBoard(int n, vector<int>& row)
    {
        assert(row.size() == n);
        vector<string> board(n, string(n, '.'));
        for(int i = 0; i < n; i++)
            board[i][row[i]] = 'Q';
        return board;
    }
    
};


int main(void)
{
    Solution s;
    auto res = s.solveNQueens(8);
    for(auto i : res)
    {
        for(auto j : i)
            cout << j << "  ";
        cout << endl;
    }
}