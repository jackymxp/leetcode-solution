#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty())
            return "";
        size_t len = INT_MAX;
        for(auto& i : strs)
            len = min(len, i.size());

        string res;
        for(int j = 0; j < len; j++)
        {
            char c = strs[0][j];
            for(int i = 1; i < strs.size(); i++){
                if(strs[i][j] != c)
                    return res;
            }
            res += c;
        }
        return res;
    }
};

int main(void){
    Solution s;
    vector<string> para = {"flower","flow","flight"};
    string res = s.longestCommonPrefix(para);
    cout << res << endl;
    return 0;
}