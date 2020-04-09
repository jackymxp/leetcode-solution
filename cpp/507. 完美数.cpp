#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num <= 1)
            return false;
        vector<int> tmp;
        int tt = sqrt(num);
        tmp.push_back(1);
        for(int i = 2; i <= tt; i++)
        {
            if(num % i == 0)
            {
                tmp.push_back(i);
                tmp.push_back(num / i);
            }       
        }
        int sum = 0;
        for(auto i : tmp)
            sum += i;
        cout << sum << endl;
        return num == sum;
    }
};