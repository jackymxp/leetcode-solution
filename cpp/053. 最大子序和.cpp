#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        if(len == 0)
            return 0;
        if(len == 1)
            return nums[0];
        vector<int> dp;
        dp.push_back(nums[0]);
        //dp[i] = max(dp[i-1] + nums[i] + nums[i])
        int res = nums[0];
        for(int i = 1; i < len; i++)
        {
            dp.push_back(max(dp[i-1] + nums[i], nums[i]));
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int res = s.maxSubArray(arr);
    cout << res << endl;
}
