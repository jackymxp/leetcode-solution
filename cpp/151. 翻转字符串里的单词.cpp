#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        //去掉开头和结尾得空格
        int len = s.size();
        int start = 0;
        int end = len-1;
        while (start < s.size() && s[start] == ' ') start++;//首空格
        while (end >= 0 && s[end] == ' ') end--;            //尾空格

        string res; 
        while(start <= end)
        {
            if(s[start] == ' ')
            {
                res += ' ';
                while(s[start] == ' ')
                    start++;
            }
            else
            {
                res += s[start];
                start++;
            }       
        }

        vector<int> posOfBlank;
        posOfBlank.push_back(-1);
        for(int i = 0; i < res.size(); i++)
            if(res[i] == ' ')
                posOfBlank.push_back(i);
        posOfBlank.push_back(res.size());

        for(int i = 0; i < posOfBlank.size() - 1; i++)
            reverse(res.begin() + posOfBlank[i]+1, res.begin() + posOfBlank[i+1]);
        reverse(res.begin(), res.end());
        return res;
    }
};


int main(int argc, char* argv[])
{
    Solution s;
    string str = "  hello world!  ";
    string res = s.reverseWords(str);
    cout << "kk" << res << "kk" << endl;
}