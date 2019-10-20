#include <iostream>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> setting;
        for(auto s : words)
        {
            string tmp;
            for(auto i : s)
            {
                tmp += code[i-'a'];
            }
            setting.insert(tmp);
        }
        return setting.size();
    }
private:
    string code[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
};


int main(void)
{
    Solution s;
    vector<string> arr = {"gin", "zen", "gig", "msg"};
    cout << s.uniqueMorseRepresentations(arr) << endl;
    return 0;
}