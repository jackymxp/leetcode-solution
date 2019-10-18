#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = s.size();
        int pos = len - 1;
        int res = 0;
        for(pos = len - 1; pos >= 0; pos--)
        {
            if(s[pos] != ' ')
                res++;
            else
            {
                if(res)
                    return res;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    cout << s.lengthOfLastWord(" a") << endl;
    return 0;
}