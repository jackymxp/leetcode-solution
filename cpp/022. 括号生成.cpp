#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path = "";
        dfs(res, 0, 0, n, path);
        return res;
    }
    void dfs(vector<string>& res, int left, int right, int n, string path)
    {
        if(right > left || left > n || right > n)
            return ;
        if(n == left && n == right){
            res.push_back(path);
            return;
        }
        dfs(res, left+1, right, n, path+"(");
        dfs(res, left, right+1, n, path+")");
    }
};