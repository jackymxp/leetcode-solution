#include <iostream>

using namespace std;

class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num <= 0)
            return false;
        int i = 1;
        while(num > 0)
        {
            num -= i;
            i += 2;
        }
        return num == 0;
    }
};

int main(void)
{
    return 0;
}