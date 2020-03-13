#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int len = nums.size();
        int res = nums[0];
        int count = 1;
        for(int i = 1; i < len; i++)
        {
            if(count == 0)
                res = nums[i];
            if(nums[i] == res)
            {
                count++;
            }
            else
            {
                count--;
            }
        }
        return res;
    }
};

int main(void)
{
    Solution s;
    vector<int> nums = {2,2,1,1,1,2,2};
    int res = s.majorityElement(nums);
    cout << res << endl;
}