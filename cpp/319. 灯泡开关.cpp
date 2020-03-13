#include <iostream>
#include <cmath>

using namespace std;
class Solution {
public:
    int bulbSwitch(int n) {
        return sqrt(n);
    }
};

int main(void)
{
    Solution s;
    int res = s.bulbSwitch(101);
    cout << res << endl;
}