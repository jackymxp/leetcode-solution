#include <iostream>

using namespace std;

class Solution {
public:
    int numTrees(int n) {
        if(n == 0)
            return 1;
        else if(n == 1)
            return 1;
        else if(n == 2)
            return 2;
        else if(n == 3)
            return 5;
        //以i做为根结点，[1, i-1]为左树，[i+1, n]为右树
        int res = 0;
        for(int i = 1; i <= n; i++)
        {
            res += numTrees(i-1) * numTrees(n-i);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    int num = 4;
    cout << s.numTrees(num) << endl;
    return 0;
}