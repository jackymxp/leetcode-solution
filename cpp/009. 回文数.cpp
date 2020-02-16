#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;
        int r = x;
       unsigned long long t = 0;
        while(x){
            t = t * 10 + (x % 10);
            x /= 10;
        }
        return r == t; 
    }
};

int main(void)
{
    Solution s;
    bool res = s.isPalindrome(1001);
    cout << res << endl;
}