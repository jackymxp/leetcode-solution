#include <iostream>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i /= 2){
            if(i % 2 != 0)
                res *= x;
            x *= x;
        }
        return n > 0 ? res : 1.0 / res;
        /*
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;
        double tmp = myPow(x, n / 2);
        if(n & 0x1)
            return n > 0 ? tmp * tmp * x : 1 / x * tmp * tmp;
        else
            return tmp * tmp;
            */
    }
};

int main(void)
{
    Solution s; 
    double a = 2;
    int b = -3;
    double res  = s.myPow(a, b);
    cout << "res = " << res << endl;
}