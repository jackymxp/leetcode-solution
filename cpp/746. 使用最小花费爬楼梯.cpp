#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> tmp(cost.size()+1, -1);
        return min(minCostClimbingStairs(cost, 0, tmp), minCostClimbingStairs(cost, 1, tmp));
    }
    int minCostClimbingStairs(vector<int>& cost, int step, vector<int>& tmp)
    {
        if(step >= cost.size())
            return 0;
        if(tmp[step] != -1)
            return tmp[step];
        tmp[step] = min(minCostClimbingStairs(cost, step+1, tmp), minCostClimbingStairs(cost, step+2, tmp)) + cost[step];
        return tmp[step];
    }
};

int main()
{
    //vector<int> arr = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
    vector<int> arr = {1,0,0,0};
    Solution s;
    int res = s.minCostClimbingStairs(arr);
    cout << res << endl;
}