#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i = left; i <= right; i++)
        {
            auto tmp = i;
            bool flag = false;
            while(tmp)
            {
                int k = tmp % 10;
                if(k == 0 || i % k != 0)
                {
                    flag = true;
                    break;
                }
                tmp /= 10;
            }
            if(flag == false)
            {
                res.push_back(i);
            }
        }
        return res;
    }
};