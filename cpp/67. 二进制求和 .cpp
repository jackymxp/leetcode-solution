#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        addBinary(a, b, false, res);
        reverse(res.begin(), res.end());
        return res;
    }
    void addBinary(string a, string b, bool flag, string& res)
    {
        if(a.empty() && b.empty() && flag == false)
            return ;
        int x = a.empty() ? 0 : a[a.size()-1] - '0';
        int y = b.empty() ? 0 : b[b.size()-1] - '0';
        int sum = x + y + flag;
        flag = sum / 2;
        res += to_string(sum % 2);
        addBinary(a.substr(0, a.size()-1), b.substr(0, b.size()-1), flag, res);
    }
};

int main(void){
    return 0;
}