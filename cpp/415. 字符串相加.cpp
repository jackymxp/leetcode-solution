#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
    string res;
public:
    string addStrings(string num1, string num2) {
        addStrings(num1, num2, false);
        reverse(res.begin(), res.end());
        return res;
    }

    void addStrings(string num1, string num2, bool flag)
    {
        if(num1.empty() && num2.empty() && flag == false)
            return;
        int a = num1.empty() == true ? 0 : num1[num1.size()-1] - '0';
        int b = num2.empty() == true ? 0 : num2[num2.size()-1] - '0';
        int sum = a + b + flag;
        flag = sum / 10;
        res += to_string(sum % 10);
        addStrings(num1.substr(0, num1.size()-1), num2.substr(0, num2.size()-1), flag);
    }
};