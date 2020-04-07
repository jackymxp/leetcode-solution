#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string toLowerCase(string str) {
        for(auto &c : str)
        {
            if(c >= 'A' && c <= 'Z')
                c += 32;
        }
        return str;
    }
};

int main(void){
    Solution s;
    string str = "JKDJKFDF";
    auto res = s.toLowerCase(str);
    cout << res << endl;
}