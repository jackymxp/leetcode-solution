#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty())
            return -1;
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int mid = ((right - left) >> 1) + left;
            if(nums[mid] == target)
                return mid;
            //[left, mid]单调递增
            if(nums[left] <= nums[mid])
            {
                if(nums[left] <= target && target <= nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            }
            else if(nums[mid] <= nums[right])
            {
                if(nums[mid] <= target && target <= nums[right])
                    left = mid + 1;
                else
                    right = mid -1;
            }
        }
        return -1;
    }
};


int main(void)
{
    return 0;
}