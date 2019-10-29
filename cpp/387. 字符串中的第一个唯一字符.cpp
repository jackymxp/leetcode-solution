#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> hash_table(26, 0);

        for(char i : s)
            hash_table[i-'a']++;
        int len = s.size();
        for(int i = 0; i < len; i++)
        {
            if(hash_table[(s[i] - 'a')] == 1)
                return i;
        }
        return -1;
    }
};

int main(void)
{
    Solution s;
    string arr = "leetcode";
    cout << s.firstUniqChar(arr) << endl;
    return 0;
}