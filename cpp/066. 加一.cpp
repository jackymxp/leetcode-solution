#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int len = digits.size();
        digits[digits.size()-1] += 1;
        int flag = 0;
        for(int i = len - 1; i >= 0; i--)
        {
            //cout << i << "  " << digits[i] << endl;
            int tmp = digits[i] + flag;
            flag = tmp / 10;
            digits[i] = tmp % 10;   
        }
        if(flag)
        {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};


int main(void)
{
    Solution s;
    vector<int> arr = {9, 9, 9, 9, 9, 9, 9, 9};
    auto res = s.plusOne(arr);
    for(auto i : res)
        cout << i << " ";
    cout << endl;
}