#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)
            return 0;
        int res = 0;
        int left = 0, right = 0;//[left, right]
        int len = nums.size();
        int tmp = 1;

        while(right < len)
        {
            tmp *= nums[right];
            while(tmp >= k)
            {
                tmp /= nums[left];
                left++;
            }
            res += right-left+1;
            right++;
        }
        return res;
    }
};


int main(void){
    Solution s;
}